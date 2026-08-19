# Counting Triangles

Goodeat finds an undirected complete graph with n vertices. Each edge of the graph is painted black or white. He wants you to help him find the number of triangles (a, b, c) (a < b < c), such that the edges between (a, b), (b, c), (c, a) have the same color. To avoid the input scale being too large, we use the following code to generate edges in the graph.

```cpp
namespace GenHelper
{
    unsigned z1,z2,z3,z4,b,u;
    unsigned get()
    {
        b=((z1<<6)^z1)>>13;
        z1=((z1&4294967294U)<<18)^b;
        b=((z2<<2)^z2)>>27;
        z2=((z2&4294967288U)<<2)^b;
        b=((z3<<13)^z3)>>21;
        z3=((z3&4294967280U)<<7)^b;
        b=((z4<<3)^z4)>>12;
        z4=((z4&4294967168U)<<13)^b;
        return (z1^z2^z3^z4);
    }
    bool read() {
      while (!u) u = get();
      bool res = u & 1;
      u >>= 1; return res;
    }
    void srand(int x)
    {
        z1=x;
        z2=(~x)^0x233333333U;
        z3=x^0x1234598766U;
        z4=(~x)+51;
      	u = 0;
    }
}
using namespace GenHelper;
bool edge[8005][8005];
int main() {
  int n, seed;
  cin >> n >> seed;
  srand(seed);
  for (int i = 0; i < n; i++)
    	for (int j = i + 1; j < n; j++)
        	edge[j][i] = edge[i][j] = read();
 	return 0;
}
```

The *edge* array in the above code stores the color of the edges in the graph. *edge[i][j]=1* means that the edge from i to j is black, otherwise it is white ($\forall 0 \le i \neq j \le n-1$).

Ensure that there is an approach that does not depend on the way the data is generated.

## 输入描述:

The first line contains two integers $n(n \le 8000), seed (seed \le 10^9)$, denote the number of vertices and the seed of random generator.

## 输出描述:

Output a line denoting the answer.

## 示例1

### 输入

```
10 114514
```

### 输出

```
35
```

### 说明

There're 35 triangles that all three edges have the same color.

## 备注: