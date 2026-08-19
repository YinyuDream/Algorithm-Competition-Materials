#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,Max;
int x[maxn];
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
bool cmp(int x,int y){
	return x>y;
}
void dfs(int step,int k,int deep,int Gcd)
{
	if(Gcd<Max&&Gcd!=-1&&n>=20)return ;
	if(step==n){
		if(k<deep)return ;
		Max=max(Max,Gcd);
		return ;
	}
	dfs(step+1,k,deep,Gcd);
	if(k+1<=deep)dfs(step+1,k+1,deep,Gcd!=-1?gcd(Gcd,x[step]):x[step]);
}
int main(){
	freopen("end.in","r",stdin);
	freopen("end.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	sort(x+1,x+n+1,cmp);
	printf("%d\n",x[1]);
	for(int i=2;i<=n;i++){
		Max=1;
		dfs(1,0,i,-1);
		printf("%d\n",Max);
	}
	return 0;
}
