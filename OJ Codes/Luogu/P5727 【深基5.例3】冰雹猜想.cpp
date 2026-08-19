#include<cstdio>
using namespace std;
int n;
void dfs(int x)
{
	if(x==1){
		printf("%d ",x);
		return ;
	}
	if(x&1)dfs(x*3+1),printf("%d ",x);
	else dfs(x>>1),printf("%d ",x);
}
int main(){
	scanf("%d",&n);
	dfs(n);
	return 0;
} 
