#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m;
int a[maxn],b[maxn];
void work()
{
	int sum=0,tot=0;
	for(int i=1;i<=n;i++)
		b[i]=a[i],sum+=a[i];
	while(sum)
	{
		b[sum]^=1;
		if(b[sum])sum++;
		else sum--;
		tot++;
	}
	printf("%d\n",tot);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch;
		scanf(" %c",&ch);
		a[i]=(ch=='T');
	}
	work();
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
			a[j]^=1;
		work();
	}
	return 0;
}
