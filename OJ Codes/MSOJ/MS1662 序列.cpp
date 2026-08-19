#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
int a[30];
inline void rev(int *st,int *ed)
{
	ed--;
	while(st<ed)swap(*st,*ed),st++,ed--;
}
void dfs(int x,int y,bool &flag,int &Max)
{
	if(x>Max)return ;
	if(flag==1)return ;
	while(a[y]==y&&y)y--;
	if(y==0){
		flag=1;return ;
	}
	int f=0;
	for(int i=2;i<=y+1;i++)if(abs(a[i]-a[i-1])>1)f++;
	if(x+f>Max)return ;
	for(int i=2;i<=y;i++)
	{
		rev(a+1,a+i+1);
		dfs(x+1,y,flag,Max);
		rev(a+1,a+i+1);
	}
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int ans=0;
		memset(a,0,sizeof a);
		scanf("%d",&n);
		for(int j=1;j<=n;j++)scanf("%d",&a[j]);
		int t=n;
		while(a[t]==t&&t)t--;
		for(int j=0;j<=2*n-2;j++)
		{
			bool flag=0;
			dfs(0,t,flag,j);
			if(flag)
			{
				printf("%d\n",j);
				break;
			}
		}
	}
	return 0;
}