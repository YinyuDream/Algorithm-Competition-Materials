# Fine Logic

## 题目描述

We consider a set $G$ consisting of $n$ entities and the relations on $G$. For simplicity, these $n$ entities are labeled from $1$ to $n$.

The **ranking** $R$ on $G$ is defined as an $n$-order permutation  

$$R = r_1, r_2, \dots, r_n \qquad (1 \le r_i \le n).$$

The **winning relation** on $G$ is defined as an ordered pair $\langle u, v\rangle$ ($1 \le u, v \le n$, $u \neq v$), representing that the entity $u$ **wins** in the competition with the entity $v$.

We say that the ranking $R$ **satisfies** the winning relation $\langle u, v\rangle$ iff there exist $1 \le i < j \le n$ such that $r_i = u$ and $r_j = v$.

Given the number of entities $n$ and $m$ winning relations, you are required to construct the minimal number of rankings such that each winning relation is satisfied by at least one ranking among the constructed rankings.

## 输入描述

The first line contains two positive integers $n, m$  

$$2 \le n \le 10^6,\qquad 1 \le m \le 10^6,$$

representing the number of entities and the number of winning relations.

Each of the following $m$ lines contains two positive integers $u, v$  

$$1 \le u, v \le n,\qquad u \neq v,$$

representing a winning relation $\langle u, v\rangle$.

## 输出描述

The first line contains a positive integer $k$, representing the minimal number of rankings needed.

Each of the following $k$ lines contains $n$ integers  

$$r_{i1}, r_{i2}, \dots, r_{in} \qquad (1 \le r_{ij} \le n),$$

representing the $i$‑th ranking $R_i = r_{i1}, r_{i2}, \dots, r_{in}$.

## 备注

本题为 **Special Judge**。

## 示例

### 输入

```text
6 4
1 4
2 3
5 6
5 3
```

### 输出

```text
1
2 5 1 6 3 4
```