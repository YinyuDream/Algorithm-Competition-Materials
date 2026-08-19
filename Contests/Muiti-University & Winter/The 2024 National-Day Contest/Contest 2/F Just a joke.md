# Just a joke

## 题目描述

Alice and Bob are playing a game.

At the beginning, there is an undirected graph $G$ with $n$ nodes.

Alice and Bob take turns to operate, Alice will play first. The player who can't operate will lose the game.

Each turn, the player should do one of the following operations.

1. Select an edge of $G$ and delete it from $G$.

2. Select a connected component of $G$ which doesn't have any loop, then delete it from $G$.

Alice and Bob are smart enough, you need to find who will win this game.

A connected component of an undirected graph is a set of nodes such that each pair of nodes is connected by a path, and other nodes in the graph are not connected to the nodes in this set.

For example, for graph with $3$ nodes and edge set $\{(1,2),(2,3),(1,3)\}.  \{1,2,3\}$ is a connected component but $\{1,2\},\{1,3\}$ are not.

## 输入描述

The first line has two integers $n,m$.

Then there are $m$ lines, each line has two integers $(u,v)$ describe an edge in $G$.

$1\leq n\leq 100$

$0\leq m\leq min(200,n(n-1)/2)$

It's guaranteed that graph $G$ doesn't have self loop and multiple edge.

## 输出描述

Output the name of the player who will win the game.

## 示例1

输入

```
3 1
1 2
```

输出

```
Bob
```