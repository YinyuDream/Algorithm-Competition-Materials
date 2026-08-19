# Election of the King

## 题目描述

In faraway Boboland, a king election is held every five years. This year is the time for another king election in Boboland. Each city in Boboland has nominated $n$ king candidates, numbered $1,2,\dots,n$. These $n$ candidates have **distinct** political tendencies $a_1,a_2,\dots,a_n$ ($1\leq a_i\leq 10^9$ represents the political tendency of the $i$-th candidate, where a larger number implies a more right-wing tendency, $1$ represents extreme left, and $10^9$ represents extreme right). Then, the following internal voting mechanism will be conducted among the candidates to decide the final king:

- There will be $n-1$ rounds of voting, and exactly one candidate will be eliminated in each round until there is only one candidate left, who will become the final king.
- The voting rule for each round is as follows: each candidate can vote for any other candidate except for themselves. The candidate with the most votes will be eliminated. If there are multiple candidates with the same highest number of votes, the one among them with the **rightmost** tendency will be eliminated.

After observing all previous king elections in Boboland, you found that each candidate adheres to the principle of attacking opponents with different opinions and will execute the following strategy in each round of voting:

Among all remaining candidates, vote for the candidate whose political tendency is most different from their own (i.e., the $i$-th candidate, if they have not been eliminated, will vote for the $j$-th candidate with the largest $|a_j-a_i|$, who has not been eliminated). If there are multiple candidates with the largest $|a_j-a_i|$, they will vote for the one among them with the **rightmost** tendency.

Now you want to know who will become the final king in this year's election in Boboland.

## 输入描述

The first line contains a positive integer $n$ $(1\leq n\leq 10^6)$, denoting the number of candidates.

The second line contains $n$ distinct integers $a_1,a_2,\dots,a_n$ $(1\leq a_i\leq 10^9)$, denoting the political inclination of each candidate.

## 输出描述

Output an integer in a line, which represents the candidate's number who will eventually become the king.

## 示例1

### 输入

```
4
5 1 8 10
```

### 输出

```
1
```

## 示例2

### 输入

```
4
10 1 9 6
```

### 输出

```
3
```

## 示例3

### 输入

```
4
3 7 5 1
```

### 输出

```
4
```

## 备注

To aid understanding, we provide a graphical illustration of the first sample test case. The following picture shows the first round of voting, with each candidate's preferred candidate indicated in the bubbles. At this point, candidates 2 and 4 are tied for the most number of votes, but candidate 4 has a more right-wing political leaning ($a_4 > a_2$), so candidate 4 is eliminated.

![image1](https://uploadfiles.nowcoder.com/images/20230726/0_1690359438947/2AE17892FDE6AE37B144F7AEF259B0FE)

The following diagram shows the second round of voting, with candidate 2 receiving the most number of votes and candidate 4 being eliminated.

![image2](https://uploadfiles.nowcoder.com/images/20230726/0_1690359448032/26F1179D15F6F405179B55F232A3A7AC)

The following diagram shows the third round of voting, with candidates 1 and 3 tied for the most number votes, but candidate 3 having a more right-wing political leaning ($a_3 > a_1$), so candidate 3 is eliminated.

![image3](https://uploadfiles.nowcoder.com/images/20230731/0_1690811380609/2F6C4EC451D875F195F63F30CC8FA096)

Therefore, candidate 1 is ultimately elected as the king.

![image4](https://uploadfiles.nowcoder.com/images/20230726/0_1690359471245/A5650FCE5F91D1FC3AE4CE5439D60949)