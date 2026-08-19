#include <cstdio>
#include <algorithm>

const int maxN = 200005;

int N, K, A[maxN];
int STmin[18][maxN], STmax[18][maxN], Lg[maxN];

inline int getMin(int l, int r)
{
	int d = Lg[r - l + 1];
	return std::min(STmin[d][l], STmin[d][r - (1 << d) + 1]);
}

inline int getMax(int l, int r)
{
	int d = Lg[r - l + 1];
	return std::max(STmax[d][l], STmax[d][r - (1 << d) + 1]);
}

bool solve(int l, int r)
{
	if (l >= r)
		return true;
	int mn = getMin(l, r), mx = getMax(l, r);
	for (int i = 0; l + i <= r - i; ++i)
	{
		if (A[l + i] - K <= mn && A[l + i] + K >= mx)
			return solve(l, l + i - 1) && solve(l + i + 1, r);
		if (A[r - i] - K <= mn && A[r - i] + K >= mx)
			return solve(l, r - i - 1) && solve(r - i + 1, r);
	}
	return false;
}

void work()
{
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; ++i)
		scanf("%d", A + i);
	Lg[0] = -1;
	for (int i = 1; i <= N; ++i)
	{
		Lg[i] = Lg[i >> 1] + 1;
		STmin[0][i] = A[i], STmax[0][i] = A[i];
	}
	for (int i = 1; i <= Lg[N]; ++i)
		for (int j = 1; j + (1 << i) - 1 <= N; ++j)
		{
			STmin[i][j] = std::min(STmin[i - 1][j], STmin[i - 1][j + (1 << i - 1)]);
			STmax[i][j] = std::max(STmax[i - 1][j], STmax[i - 1][j + (1 << i - 1)]);
		}
	puts(solve(1, N) ? "Yes" : "No");
}

int main()
{
	int T;
	for (scanf("%d", &T); T--;)
		work();

	return 0;
}
