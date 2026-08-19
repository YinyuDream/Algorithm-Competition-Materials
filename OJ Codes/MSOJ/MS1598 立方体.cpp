#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,p=1e9+7;
int n,k;
int a[maxn],inv[maxn];
int qpow(int a,int b)
{
	if(b==0)return 1;
	int c=qpow(a,b/2);
	c=1ll*c*c%p;
	if(b&1)c=1ll*c*a%p;
	return c;
}
int C(int x,int y)
{
	int ans=1;
	for(int i=n-k+1;i<=n;i++)
		ans=1ll*ans*i%p;
	for(int i=2;i<=k;i++)
		ans=1ll*ans*inv[i]%p;
	return ans;
}
int main(){
	//freopen("cube.in","r",stdin);
	//freopen("cube.out","w",stdout);
	scanf("%d%d",&n,&k);
	k=min(k,n-k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=k;i++)
		inv[i]=qpow(i,p-2);
	printf("%d\n",C(n,k));
	return 0;
}