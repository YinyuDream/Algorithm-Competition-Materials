#include<cstdio>
using namespace std;
int n,k,cnt;
void dfs(int x,int num,int pre)
{
	if(x==k+1){
		if(num!=0)return ;
		cnt++;return ;
	}
	for(int i=pre;i<=num;i++)
	dfs(x+1,num-i,i);
}
int main(){
	scanf("%d%d",&n,&k);
	dfs(1,n,1);
	printf("%d",cnt);
	return 0;
}
