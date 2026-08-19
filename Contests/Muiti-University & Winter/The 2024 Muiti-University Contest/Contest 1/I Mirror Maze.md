# Mirror Maze

## 题目描述

There is an $n\times m$ mirror maze, where there is a mirror on each grid. The mirrors are in one of the following four types:

- ``-'', the light from above or below will be reflected back, the light from left or right will continue going forward without being reflected, respectively;
- ``|'', the light from left or right will be reflected back, the light from above or below will continue going forward without being reflected, respectively;
- ``/'', the light from left, right, above, below will be reflected to go above, below, left, right, respectively;
- ``\backslash'', the light from left, right, above, below will be reflected to go below, above, right, left, respectively.

Now there are $q$ light sources. Little G, the believer of the light, wants to know the numbers of different mirrors the emitted light will be reflected by within sufficient time for each light source.

## 输入描述

The first line contains two integers $n,m\,(1 \le n,m \le 1\,000)$, denoting the size of the mirror maze.

Each of the following $n$ lines contains a string of length $m$, where the $j$-th character in the $i$-th line $S_{i,j}\,(S_{i,j} \in \{|, -, /, \backslash\})$ denotes the mirror on grid $(i,j)$.

The next line contains an integer $q\,(1 \le q \le 10^5)$, denoting the number of light sources.

Each of the following $q$ lines contains two integers $u\,(1 \le u \le n)$, $v\,(1 \le v \le m)$ and a string $dir\,(dir \in \{above, below, left, right\})$, denoting that a light source is on grid $(u,v)$ and emits light going along the $dir$ direction. Specifically, the light will not be influenced by the mirror on grid $(u,v)$ initially.

## 输出描述

Output $q$ lines each containing one integer, denoting the number of different mirrors the emitted light will be reflected by within sufficient time for each light source.

## 样例输入

```plain
2 3
/\-
\/|
2
1 2 below
2 2 right
```

## 样例输出

```plain
4
2
```

## 说明

- For the first light, it will be reflected by the mirrors at $(2,2), (2,1), (1,1), (1,2)$ repeatedly and stay in the mirror maze.
- For the second light, it will be reflected by $(2,3)$ and go back to $(2,2)$, then reflected by $(2,2)$, go below, and get away from the mirror maze.