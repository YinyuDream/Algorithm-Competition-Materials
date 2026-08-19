#include<cstdio>
using namespace std;
long long sum,mul,add;
int n,m;
long long a[50000000+10];
int main(){
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d%d",&n,&m);
	mul=1,add=0;
	sum=n*(n+1)/2;
	for(int i=1;i<=n;i++)
		a[i]=i;
	for(int j=1;j<=m;j++)
	{
		char opt;
		int p,q;
		scanf(" %c %d%d",&opt,&p,&q);
		//printf("%c %d %d\n",opt,p,q);
		if(opt=='A'){
			sum=n*(n+1)/2;
			sum=p*n*(n+1)/2+n*q;
			mul=p,add=q;
		}
		else if(opt=='B'){
			int tmp=a[p]*mul+add;
			sum=sum+(q-tmp);
			a[p]=q;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
