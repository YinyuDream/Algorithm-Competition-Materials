#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n;
int a[maxn];
void dfs(int pre,int x)
{
	if(x<0)return ;
	if(x==0){
		if(pre==1)return ;
		for(int i=1;i<=pre;i++)
			printf("%d%c",a[i],i==pre?'\n':'+');
		return ;
	}
	for(int i=a[pre];i<=n;i++)
	a[pre+1]=i,dfs(pre+1,x-i);
}
int main(){
	scanf("%d",&n);
	a[0]=1;
	dfs(0,n);
	return 0;
}
