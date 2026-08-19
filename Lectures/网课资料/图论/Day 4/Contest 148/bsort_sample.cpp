#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn=100010;

int n,q,y[maxn],z[maxn];

void merge_sort(int l,int r)
{
	if (l==r) return;
	int m=(l+r)>>1;
	merge_sort(l,m);
	merge_sort(m+1,r);
	int p1=l,p2=m+1;
	int v=0;
	for (int a=l;a<=r;a++)
	{
		if (p1>m) y[a]=z[p2++];
		else if (p2>r) y[a]=z[p1++];
		else if (z[p1]<z[p2]) y[a]=z[p1++];
		else
		{
			y[a]=z[p2++];
			v+=m-p1+1;
		}
	}
	for (int a=l;a<=r;a++)
		z[a]=y[a];
	printf("%d ",v);

}

int main()
{
	scanf("%d",&n);
	for (int a=1;a<=n;a++)
		scanf("%d",&z[a]);
	merge_sort(1,n);
	printf("\n");

	return 0;
}
