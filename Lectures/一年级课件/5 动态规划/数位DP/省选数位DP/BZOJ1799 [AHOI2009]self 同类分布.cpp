#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[20];
long long f[20][200][200];
long long dfs(int pos,int sum,int val,int mod,bool limit)
{
	if(pos==0) return sum==0&&val==0;
	if(!limit&&f[pos][sum][val]!=-1) return f[pos][sum][val];
	int up=limit?a[pos]:9;
	long long temp=0;
	for(int i=0;i<=up;i++)
	{
		if(sum-i<0) break;
		temp+=dfs(pos-1,sum-i,(val*10+i)%mod,mod,limit&&i==a[pos]);
	}
	if(!limit) f[pos][sum][val]=temp;
	return temp;
}
long long solve(long long x)
{
	int cnt=0;
	while(x)
	{
		a[++cnt]=x%10;
		x/=10;
	}
	long long temp=0;
	for(int i=1;i<=cnt*9;i++)
		memset(f,-1,sizeof(f)),
			temp+=dfs(cnt,i,0,i,true);
	return temp;
}

int main()
{
	long long aa,bb;
	scanf("%lld%lld",&aa,&bb);
	printf("%lld\n",solve(bb)-solve(aa-1));
	return 0;
}
