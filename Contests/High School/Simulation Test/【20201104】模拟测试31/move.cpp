#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,p=1e9+7;
int n,m,T;
int inv[maxn];
int qpow(int a,int b)
{
	if(b==0)return 1;
	int t=qpow(a,b/2);
	t=1ll*t*t%p;
	if(b&1)t=1ll*t*a%p;
	return t;
}
int C(int x,int y)
{
	int ans=1;
	for(int i=2;i<=x;i++)
		ans=1ll*ans*i%p;
	for(int i=2;i<=y;i++)
		ans=1ll*ans*inv[i]%p;
	for(int i=2;i<=x-y;i++)
		ans=1ll*ans*inv[i]%p;
	return ans;
}
int main(){
	freopen("move.in","r",stdin);
	freopen("move.out","w",stdout);
	for(int i=1;i<maxn;i++)
		inv[i]=qpow(i,p-2);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n<m)swap(n,m);
		n--,m--;
		printf("%d\n",C(n+m-2,m-1));
	}
	return 0;
}
