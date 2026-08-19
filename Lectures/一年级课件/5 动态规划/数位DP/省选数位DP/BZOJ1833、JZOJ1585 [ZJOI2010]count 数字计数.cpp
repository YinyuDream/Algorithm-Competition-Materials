//WA
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[25];
int f[25][25][25][2];
long long dfs(int pos,int p,int cnt,bool zero,bool limit)
{
	if(!pos) return cnt;
	if(!limit&&f[pos][p][cnt][zero]!=-1) return f[pos][p][cnt][zero];
	int up=limit?a[pos]:9;
	long long temp=0;
	for(int i=0;i<=up;i++)
		temp+=dfs(pos-1,p,cnt+((i==p)&&((p==0&&zero)||(p!=0))),zero||(i!=0),limit&&(i==a[pos]));
	if(!limit) f[pos][p][cnt][zero]=temp;
	return temp;
}
long long get(long long x,int num)
{
	int top=0;
	while(x)
	{
		a[++top]=x%10;
		x/=10;
	}
	return dfs(top,num,0,false,true);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("1833.in","r",stdin);
	#endif
	memset(f,-1,sizeof(f));
	long long aa,bb;
	scanf("%lld%lld",&aa,&bb);
	for(int i=0;i<=9;i++) printf("%lld ",get(bb,i)-get(aa-1,i));
	return 0;
}
