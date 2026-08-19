#include<cstdio>
using namespace std;
const int maxn=30;
int n,m;
long long ans;
int p[maxn];
inline long long gcd(long long x,long long y){
	return y==0?x:gcd(y,x%y);
}
inline long long lcm(long long x,long long y){
	return x*y/gcd(x,y);
}
void dfs(int step,long long Lcm,int k)
{
	if(Lcm>n)return ;
	if(step==m+1)
	{
		if(k==0)return ;
		if(k&1)ans+=n/Lcm;
		else ans-=n/Lcm;
		return ;
	}
	dfs(step+1,lcm(Lcm,p[step]),k+1);
	dfs(step+1,Lcm,k);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&p[i]);
	dfs(1,1,0);
	printf("%lld",n-ans);
	return 0;
}
