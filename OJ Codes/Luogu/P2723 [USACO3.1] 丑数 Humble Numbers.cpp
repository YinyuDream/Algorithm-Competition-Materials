#include<cstdio>
#include<queue>
#include<set>
#define int long long 
using namespace std;
const int maxn=120;
int n,k,cnt,p;
int a[maxn],f[(int)1e6+10],s[(int)1e6+10];
set<int>Set;
signed main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	f[0]=1;
	for(int i=1;i<=k;i++)
	{
		int minx=0x7f7f7f7f;
		for(int j=1;j<=n;j++)
		{
			while(a[j]*f[s[j]]<=f[i-1])s[j]++;
			if(a[j]*f[s[j]]<=minx)minx=a[j]*f[s[j]];
		}
		f[i]=minx;
	}
	printf("%lld",f[k]);
	return 0;
} 