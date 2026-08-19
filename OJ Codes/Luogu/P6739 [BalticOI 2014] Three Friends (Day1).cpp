#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
const int maxn=2e6+10,p=131;
int n;
char a[maxn];
ull hash[maxn];
int main()
{
	scanf("%d\n%s",&n,a+1);
	for(int i=1;i<=n;i++)
		hash[i]=(hash[i-1]*p+a[i]);
	
	return 0;
}
