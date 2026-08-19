#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

//#define LOCAL_CHECK

int Case, n, P[N];

inline void Up(int st, int d, int &ptr)
{
	for (int i = st; i <= n; i += d)
		P[ptr ++] = i;
}

inline void Down(int st, int d, int &ptr)
{
	int _ptr = ptr;
	Up(st, d, ptr);
	reverse(P + _ptr, P + ptr);
}

int main()
{
#ifndef LOCAL_CHECK
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d", &n);
#else
	static const int lim = N << 1;
	static bool Flag[lim];
	for (int i = 2; i < lim; i ++)
		if (!Flag[i])
			for (int j = 2 * i; j < lim; j += i)
				Flag[j] = true;
	Flag[0] = Flag[1] = Flag[2] = true;
	for (n = 2; n <= 1000; n ++)
	{
#endif
		int ptr = 1;
		if (n <= 4)
		{
			// 1,2,...,n
			Up(1, 1, ptr);
		}
		else if (n % 5 == 0)
		{
			// 5/2\1/4\3
			Up(5, 5, ptr);
			Down(2, 5, ptr);
			Up(1, 5, ptr);
			Down(4, 5, ptr);
			Up(3, 5, ptr);
		}
		else if (n % 5 == 1)
		{
			// 5/2\1(6)/3\4
			Up(5, 5, ptr);
			Down(2, 5, ptr);
			Up(1, 5, ptr);
			Down(3, 5, ptr);
			Up(4, 5, ptr);
		}
		else if (n % 5 == 2)
		{
			// 3/(6)1\4/(7)2\5
			Up(3, 5, ptr);
			Down(1, 5, ptr);
			Up(4, 5, ptr);
			Down(2, 5, ptr);
			Up(5, 5, ptr);
		}
		else if (n % 5 == 3)
		{
			// 5/(8)3\2(7)/4\1
			Up(5, 5, ptr);
			Down(3, 5, ptr);
			Up(2, 5, ptr);
			Down(4, 5, ptr);
			Up(1, 5, ptr);
		}
		else
		{
			// 5/(8)3\4(9)/(6)1\2
			Up(5, 5, ptr);
			Down(3, 5, ptr);
			Up(4, 5, ptr);
			Down(1, 5, ptr);
			Up(2, 5, ptr);
		}
#ifndef LOCAL_CHECK
		for (int i = 1; i <= n; i ++)
			printf("%d%c", P[i], i == n ? '\n' : ' ');
#else
		int err_pos = 0;
		for (int i = 1; !err_pos && i < n; i ++)
		{
			int sum = P[i] + P[i + 1];
			int diff = P[i] > P[i + 1] ? P[i] - P[i + 1] : P[i + 1] - P[i];
			if (Flag[sum] && Flag[diff])
				err_pos = i;
		}
		if (err_pos != 0)
		{
			fprintf(stderr, "n = %d, err_pos = %d\n", n, err_pos);
			for (int i = 1; i <= n; i ++)
				printf("%d%c", P[i], i == n ? '\n' : ' ');
			break ;
		}
		else fprintf(stderr, "n = %d : OK\n", n);
#endif
	}
	return 0;
}
