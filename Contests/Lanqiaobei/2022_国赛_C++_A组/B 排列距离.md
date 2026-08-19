# 排列距离

### 问题描述

小蓝最近迷上了全排列, 现在他有一个长度为 17 的排列, 里面包含的元素 有: abcdefghijklnopqr, 即 a 至 $r$ 中除了 $m$ 以外的所有小写字母, 这 17 个字母在任何一个排列中都恰好出现一次。前面几个排列依次是：

第 1 个排列为: abcdefghijklnopqr;

第 2 个排列为: abcdefghijklnoprq;

第 3 个排列为: abcdefghijklnoqpr;

第 4 个排列为: abcdefghijklnogrp;

第 5 个排列为: abcdefghijklnorpq;

第 6 个排列为: abcdefghijklnorqp;

第 7 个排列为: abcdefghijklnpoqr;

第 8 个排列为: abcdefghijklnporq;

第 9 个排列为: abcdefghijklnpqor;

第 10 个排列为: abcdefghijklnpqro。

对于一个排列, 有两种转移操作:

1) 转移到其下一个排列。如果当前排列已经是最后一个排列, 那么下一个 排列就是第一个排列。

2) 转移到其上一个排列。如果当前排列是第一个排列, 那么上一个排列就 是最后一个排列。



小蓝现在有两个排列, 分别为排列 $A:$ aejcldbhpiogfqnkr, 以及排列 $B$ : ncfjboqiealhkrpgd, 他现在想知道, 在只有上述两种转移操作的前提 下, 排列 $A$ 最少转移多少次能得到排列 $B$ 。



### 答案提交 

这是一道结果填空的题，你只需要算出结果后提交即可。本题的结果为一 个整数, 在提交答案时只填写这个整数, 填写多余的内容将无法得分。