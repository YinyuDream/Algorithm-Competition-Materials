#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,t;
struct number
{
	int xb,num;
};
number a[maxn];
bool cmp(number x,number y)
{
	return x.num<y.num;
}
int find(int left,int right,int x)
{
	while(left+1<right)
	{
		int mid=(left+right)/2;
		if(a[mid].num<=x)left=mid;
		else right=mid;
	}
	return left;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].num),a[i].xb=i;
	sort(a+1,a+n+1,cmp);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&t);
		int temp=find(1,n,t);
		
		if(a[temp].num==t)printf("%d\n",a[temp].xb);
		else printf("-1\n");
	}
	return 0;
}