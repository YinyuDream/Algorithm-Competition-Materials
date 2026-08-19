# std::pair

## 题目描述

Perhaps you are familiar with $\texttt{std::pair}$ in C++: it creates a pair of two types and provides basic functionalities.

For instance, for the types $\texttt{double}$ and $\texttt{int}$, a $\texttt{pair}$ of them would be $\texttt{pair<double,int>}$. You can access the $\texttt{double}$ member by $\texttt{.first}$ and the $\texttt{int}$ member by $\texttt{.second}$. Similarly, you can access the $\texttt{int}$ member of a $\texttt{pair<int,double>}$ by $\texttt{.first}$, and the $\texttt{double}$ member by $\texttt{.second}$.

Using a $\texttt{pair}$ is convenient when you need a quick combination of two data types. However, it can become quite complex when using nested pairs, such as $\texttt{pair}$ of a $\texttt{pair}$, $\texttt{pair}$ of a $\texttt{pair}$ of a $\texttt{pair}$, etc. Your task is to write a helper program that displays the types of members in these nested pairs.

For this problem, we only consider types created recursively by the following rules:
- Basic types are $\texttt{double}$ and $\texttt{int}$.
- For two possible types $A$ and $B$, $\texttt{pair<A,B>}$ is a possible type.

## 输入描述

The first line contains two integers $n, q ~ (1 \leq n, q \leq 1000)$, the number of variable declarations and queries.

Each of the following $n$ lines contains a line in the following format: 
```
[type name] [variable name];
```
where the $\texttt{type name}$ is a string denoted a type defined above, and the $\texttt{variable name}$ is a non-empty string consisting of letters (uppercase or lowercase, $\textbf{case sensitive}$), digits, and underscores (_, ascii 95), which must not start with a digit. There will not be any extra spaces except one single space between $\texttt{type name}$ and $\texttt{variable name}$.

For the next $q$ lines, each contains a query string. Possible formats are defined recursively by the following rules:

$\texttt{variable name}$ is a possible query.
If $A$ is a possible query and $A$ is a pair, $A\texttt{.first}$ and $A\texttt{.second}$ are possible queries.

It is guaranteed that each line of input contains at most $5000$ characters, no two variables share the same name, and each query must correspond correctly to a previously defined variable.

## 输出描述

For each query, print a line of string in the same format of $\texttt{type name}$ in the input, which must not contain extra spaces.

## 样例输入输出

### 样例输入

```plain
3 3
int a;
pair<int,int> E6;
pair<pair<double,int>,double> __Fukami;
a
E6
__Fukami.first.second
```

### 样例输出

```plain
int
pair<int,int>
int
```