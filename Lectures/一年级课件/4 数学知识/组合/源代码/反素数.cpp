#include<cstdio>
using namespace std;
const int maxn=1e3+10;
long long n,ans,c;
int a[]={0,2,3,5,7,11,13,17,19,23,29};
long lon pow(long long x,long long p)
{
	if(p==1)return x;
	if(p==0)return 1;
	if(p%2==1)return pow(x,p/2)*pow(x,p/2);
	else return pow(x,p/2)*pow(x,p/2)*x;
}
void dfs(long long step,long long num,long long k,long long cnt)
{
	printf("%lld   %lld   %lld\n",k,step,num);
	if(num>n||(cnt*(k+1)<c&&num>ans))return ;
	if(step>=11){
		if(c<cnt)c=cnt,ans=num;
		else if(c==cnt&&ans>num)ans=num;
		return ;
	}
	for(int i=k;i>=0;i--)dfs(step+1,num*pow(a[step],i),i,cnt*(i+1));
}
int main(){
	scanf("%lld",&n);
	dfs(1ll,1ll,30,1ll);
	printf("%lld",ans);
	return 0;
}
