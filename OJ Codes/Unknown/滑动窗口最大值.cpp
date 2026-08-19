#include<cstdio>
using namespace std;

const int maxn=1e6+10;
int n,k,x;
int l1,l2,r1,r2,k1=1,k2=1;
int ansmin[maxn],ansmax[maxn];

struct node
{
	int s,id;
};
node a[maxn],b[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		while((l1!=r1&&a[r1].s<=x))	r1--;
		a[++r1].s=x;
		a[r1].id=i;
		if(k1==a[l1].id)l1++;	
		k1++;
		ansmax[i]=a[l1].s;
		
		/*while(l2!=r&&b[r2].s>=x)
			r2--;
		b[++r2].s=x;
		b[r2].id=i;
		if(k==b[l].id)
			l2++;
		k2++;
		ansmin[i]=b[l2].s;*/
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ansmax[i]);
	printf("\n");
	/*for(int i=1;i<=n;i++)
		printf("%d",ansmin[i]);
	printf("\n");*/
	return 0;
}	
