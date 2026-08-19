#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n,m,p;
int l[maxn],r[maxn],k[maxn];
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&l[i],&r[i],&k[i]);
	printf("%d",m);
	return 0;
}
