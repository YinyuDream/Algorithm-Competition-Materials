#include<cstdio>
using namespace std;
const int maxn=3e6+10;
int n,p;
int inv[maxn];
int main(){
	scanf("%d%d",&n,&p);
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=(1ll*(p-p/i)*inv[p%i])%p;
	for(int i=1;i<=n;i++)
	printf("%d\n",inv[i]);
	return 0;
}
