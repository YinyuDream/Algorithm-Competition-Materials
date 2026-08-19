#include <map>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define M 1000000 + 5

int n;
map<string, int> Map;
char str[M];

int main()
{
	scanf("%d", &n);
	int sum_c = 0, sum_len = 0;
	for (int i = 1, c; i <= n; i ++)
		for (scanf("%d", &c); c; c --)
		{
			scanf("%s", str);
		    sum_c ++;
		    sum_len += strlen(str);
			Map[string(str)] ++;
		}
	bool first = true;
	int res = 0;
	for (const pair<string, int> p : Map)
		if (p.second == n) res++;
	printf("%d\n", res);
	for (const pair<string, int> p : Map)
		if (p.second == n)
		{
			if (!first)
				putchar('\n');
			printf("%s", p.first.c_str());
			first = false;
		}
	puts("");
	fprintf(stderr, "n = %d, sum_c = %d, sum_len = %d\n", n, sum_c, sum_len);
	return 0;
}
