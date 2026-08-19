#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,top;
char a[110][12];
int map[1<<10],st[70],num[70];
int dp[110][1<<11][1<<11];
int get(int c)
{
	int cnt=0;
	while(c){
		if(c&1)cnt++;
		c>>=1;
	}
	return cnt;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",a[i]+1);
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='H')map[i]+=(1<<m-j);
		}
	}
	for(int i=0;i<=(1<<m)-1;i++)
	{
		if((i&(i<<1))||(i&(i<<2)))continue;
		st[top++]=i;
		num[top-1]=get(i);
	}
	top--;
	for(int i=0;i<=top;i++)
	{
		if((map[1]&st[i])==0)
		{
			dp[1][st[i]][0]=num[i];
		}
	}
	for(int i=0;i<=top;i++)
	{
		for(int j=0;j<=top;j++)
		{
			if((st[i]&st[j])==0&&(map[2]&st[i])==0&&(map[1]&st[j])==0)
			{
				dp[2][st[i]][st[j]]=max(dp[1][st[j]][0]+num[i],dp[2][st[i]][st[j]]);
			}
		}
	}
	for(int i=3;i<=n;i++)
	{
		for(int j=0;j<=top;j++)
		{
			for(int k=0;k<=top;k++)
			{
				if((st[k]&st[j])==0&&(map[i]&st[j])==0&&(map[i-1]&st[k])==0)
				{
					for(int l=0;l<=top;l++)
					{
						if((st[k]&st[l])==0&&(st[j]&st[l])==0&&(map[i-2]&st[l])==0)
						{
							dp[i][st[j]][st[k]]=max(dp[i-1][st[k]][st[l]]+num[j],dp[i][st[j]][st[k]]);
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=top;i++)
	{
		for(int j=0;j<=top;j++)
		{
			if((st[i]&st[j])==0)
			{
				ans=max(dp[n][st[i]][st[j]],ans);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
