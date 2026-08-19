#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=100;
int a,b;
int num[maxn],f[maxn][maxn];
int dfs(int pos,int pre,int lim,int flag)
{
	if(pos==-1)return 1;
	if(!flag&&!lim&&f[pos][pre]!=-1)
	return f[pos][pre];
	int up=lim?num[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++)
	{
		if(abs(i-pre)<2&&!flag)continue;
		ans+=dfs(pos-1,i,lim&&i==num[pos],i==0&&flag);
	}
	if(!lim&&!flag)
	f[pos][pre]=ans;
	return ans;
}
int work(int x)
{
	int cnt=0;
	//if(x>=0&&x<=9)return x;
	while(x)
	num[cnt++]=x%10,x/=10;
	return dfs(cnt-1,0,1,1);
}
int main(){
	scanf("%d%d",&a,&b);
	memset(f,-1,sizeof f);
	printf("%d\n",work(b)-work(a-1));
	return 0;
}