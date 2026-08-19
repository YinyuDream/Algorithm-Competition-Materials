# 指定编译器
CXX = g++

# 指定编译选项
CXXFLAGS = -std=c++17 -g -DHAVE_NUM -DPREFETCH

# 找到所有的.cpp文件
SOURCES = $(wildcard operator/*.cpp query/*.cpp runtime/*.cpp utils/*.cpp *.cpp)

# 对应的目标文件
OBJECTS = $(SOURCES:.cpp=.o)

# 最终生成的可执行文件
EXEC = exe

# 默认规则
all: $(EXEC)

$(EXEC): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) -o $@ $^

# 编译单个源文件
%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# 清除生成的文件
clean:
	rm -f $(OBJECTS) $(EXEC) *.out CLICK_COUNT_CHECKPOINT_*
