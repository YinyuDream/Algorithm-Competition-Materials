#include<cstdio>
using namespace std;
int a[2],n,cnt;
int top;
bool cheak(int x)
{
	if(x>=1||x<=9){
		if(x==a[0]||x==a[1])return true;
		return false ;
	}
	int sum=0,t=0;
	while(x){
		sum+=(x%10)*(++t);
		x/=10;
	}
	return cheak(sum);
}
void dfs(int sum,int step)
{
	if(step==n){
		if(cheak(sum))cnt++;return ;
	}
	for(int i=0;i<=1;i++)dfs(a[i]+sum,step+1);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d%d",&a[0],&a[1],&n);
	for(int i=0;i<=1;i++)
	dfs(a[i],1);
	printf("%d",cnt);
	return 0;
}
