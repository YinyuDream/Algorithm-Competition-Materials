#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

const int maxn=100010;

int n,y[maxn],z[maxn];

void merge_sort(int l,int r)
{
	if (l==r) return;
	int m=(l+r)>>1;
	merge_sort(l,m);
	merge_sort(m+1,r);
	int p1=l,p2=m+1;
	int v;
	scanf("%d",&v);
	int p=l;
	while (v>=m-p1+1)
	{
		y[p++]=z[p2++];
		v-=m-p1+1;
	}
	for (int a=p1;a<=m-v;a++)
		y[p++]=z[p1++];
	if (p2<=r) y[p++]=z[p2++];
	for (int a=m-v+1;a<=m;a++)
		y[p++]=z[p1++];
	while (p<=r)
		y[p++]=z[p2++];
	for (int a=l;a<=r;a++)
		z[a]=y[a];

}

int main()
{
	//freopen("bsort.in","r",stdin);
	//freopen("bsort.out","w",stdout);
	scanf("%d",&n);
	for (int a=1;a<=n;a++)
		z[a]=a;
	merge_sort(1,n);
	for (int a=1;a<=n;a++)
		y[z[a]]=a;
	for (int a=1;a<=n;a++)
		printf("%d%c",y[a],a==n?'\n':' ');

	return 0;
}
