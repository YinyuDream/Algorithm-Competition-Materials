#pragma once

#include <fstream>
#include <string>

#include "../utils/Event.h"
#include "../utils/Utils.h"

class TwoPhaseCommitFunction {
public:
    int checkpointId;

    virtual int beginCheckpoint() = 0;
    virtual void preCommit(int checkpointId) = 0;
    virtual bool commit(int checkpointId) = 0;
    virtual void abort(int checkpointId) = 0;
};

class CheckpointCoordinator : public TwoPhaseCommitFunction {
private:
    int checkpointId = 0;
    int totalOperatorNumber;
    std::string tmpFileName;
    std::string tmpDirectory;
    std::string finalDirectory;

    size_t checkpointInterval;
    std::vector<std::shared_ptr<EventQueue>> source_operators;
    std::shared_ptr<EventQueue> receive;

public:
    CheckpointCoordinator() {}
    CheckpointCoordinator(size_t checkpointInterval) : checkpointInterval(checkpointInterval) {}
    ~CheckpointCoordinator() {}

    void doCheckpoint() {
        int successOperator = 0;
        // Step 1 - 开始第checkpoint_id轮的Checkpoint过程
        int checkpoint_id = beginCheckpoint();
        // 向所有的 SourceOperator 发出 Checkpoint Barrier
        for (auto source : source_operators) {
            if (!source->try_enqueue(Event(EventType::CHECKPOINTBARRIER, checkpoint_id))) {
                //  有一个未发送成功则直接终止这次 Checkpoint 的过程
                abort(checkpoint_id);
                return;
            }
        }

        // Step 2 - 等待所有的 Operator 完成自身的 Checkpoint 过程，
        // 所有的 Operator 通过 receive 队列向 CheckpointCoordinator 返回 Success 或者 Failed
        // 流处理系统中的 preCommit 阶段即每个算子执行 do_checkpoint() 之后返回 ack 的过程
        do {
            Event ack_or_abort;
            while (receive->try_dequeue(ack_or_abort)) {
                //
                if (ack_or_abort.getType() == EventType::ACK) {
                    successOperator += 1;
                } else {
                    abort(checkpoint_id);
                    return;
                }
            }
        } while (successOperator < totalOperatorNumber);

        // Step 3 - 所有的 Operator 已经返回了 ACK，说明预提交已经成功，接下来执行 Commit 操作
        if (commit(checkpoint_id)) {
            std::cout << "Checkpoint " << checkpoint_id << " success!\n";
        } else {
            abort(checkpoint_id);
            return;
        };
    }

    // 创建临时文件，并且获得此次执行的 CheckpointID
    int beginCheckpoint() {
        checkpointId++;
        std::ofstream file(tmpDirectory + tmpFileName + std::to_string(checkpointId));
        if (file.is_open()) {
            file.close();
        }
        return checkpointId;
    }

    // 将预提交的文件原子性移动到真正的目标目录中
    bool commit(int checkpointId) {
        int result = std::rename((tmpDirectory + tmpFileName + std::to_string(checkpointId)).c_str(),
                                 (finalDirectory + tmpFileName + std::to_string(checkpointId)).c_str());
        if (result == 0) {
            return true;
        } else {
            return false;
        }
    }

    // 终止当前的 Checkpoint 的过程
    void abort(int checkpointId) {
        int result = std::remove((tmpDirectory + tmpFileName + std::to_string(checkpointId)).c_str());
        checkpointId--;
    }
};