#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int num[10010];
bool dfs(int cur,int x,int deep)
{
	if(num[cur]==n)return 1;
	if(cur>=deep)return 0;
	x=max(x,num[cur]);
	if(x*(1<<(deep-cur))<n)return 0;
	for(int i=cur;i>=0;i--)
	{
		num[cur+1]=num[cur]+num[i];
		if(dfs(cur+1,x,deep))return 1;
		if(num[cur]>num[i])num[cur+1]=num[cur]-num[i];
		else num[cur+1]=num[i]-num[cur];
		if(dfs(cur+1,x,deep))return 1;
	}
	return 0;
}
int main(){
	while(scanf("%d",&n)&&n)
	{
		int k=1;
		memset(num,0,sizeof num);
		num[0]=1;
		if(n==1){
			printf("%d\n",0);continue;
		}
		while(1)
		{
			if(dfs(0,1,k))break;
			k++;
		}
		printf("%d\n",k);
	}
	return 0;
}
