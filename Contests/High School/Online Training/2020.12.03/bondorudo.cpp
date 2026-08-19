#include<cstdio>
using namespace std;
int n,m;
int main(){
	freopen("bondorudo.in","r",stdin);
	freopen("bondorudo.out","w",stdout);
	scanf("%d%d",&n,&m);
	printf("%d\n",m-n+2);
	for(int i=1;i<n;i++)
		printf("%d %d\n",i,i+1);
	if(n==m)printf("%d %d\n",1,n);
	for(int i=n+1,l=1,r=n;i<=m;i++)
		printf("%d %d\n",l++,r--);
	return 0;
}
