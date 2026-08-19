#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[20];
long long f[20][20][2000];
long long dfs(int pos,int mid,int sum,bool limit)
{
	if(pos==0) return sum==0;
	if(!limit&&f[pos][mid][sum]!=-1) return f[pos][mid][sum];
	int up=limit?a[pos]:9;
	long long temp=0;
	for(int i=0;i<=up;i++)
	{
		temp+=dfs(pos-1,mid,sum+(mid-pos)*i,limit&&a[pos]==i);
	}
	if(!limit) f[pos][mid][sum]=temp;
	return temp;
}
long long solve(long long x)
{
	if(x==-1) return 0;
	int cnt=0;
	while(x)
	{
		a[++cnt]=x%10;
		x/=10;
	}
	long long temp=0;
	for(int i=1;i<=cnt;i++) temp+=dfs(cnt,i,0,true);
	return temp-cnt+1;//0在每个位置都统计到了，所以要减去重复的 
}
int main()
{
	int T;
	long long aa,bb;
	scanf("%d",&T);
	memset(f,-1,sizeof(f));
	while(T--)
	{
		scanf("%lld%lld",&aa,&bb);
		printf("%lld\n",solve(bb)-solve(aa-1));
	}
	return 0;
}
