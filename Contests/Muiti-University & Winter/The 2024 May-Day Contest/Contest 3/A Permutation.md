## Permutation

**Description**  
You are given a prime number $ p $, you want to find a permutation of numbers $ 1, 2, \dots, p-1 $, denoted as $ x_1, x_2, \dots, x_{p-1} $, such that for all $ i $ ($ 1 \leq i \leq p-2 $), $ x_{i+1} \equiv 2x_i \pmod{p} $ or $ x_{i+1} \equiv 3x_i \pmod{p} $.

**Input**  
The first line contains an integer $ T $ ($ 1 \leq T \leq 100 $) indicating the number of test cases.  
For each test case, there is one prime number $ p $ ($ 2 \leq p \leq 10^6 $) in the first line.  
It's guaranteed that $ \sum p \leq 10^6 $.

**Output**  
If there is no solution for this prime, print `-1`. Otherwise print $ p-1 $ integers $ x_1, x_2, \dots, x_{p-1} $.

**Example**

Input:
```
2
3
5
```
Output:
```
1 2
1 2 4 3
```
