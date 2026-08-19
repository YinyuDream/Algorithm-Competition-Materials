#include<cstdio>
#include<algorithm>
using namespace std;
int n;
struct stu
{
	char xm[30];
	int xh;
	char xb;
	int yw,sx,yy,sum;
	double pjf;
}; 
stu a[1010];
bool cmp(stu x,stu y)
{
	if(x.sum!=y.sum)return x.sum>y.sum;
	else return x.xh<y.xh;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d %c%d%d%d",a[i].xm,&a[i].xh,&a[i].xb,&a[i].yw,&a[i].sx,&a[i].yy);
		a[i].sum=a[i].yw+a[i].yy+a[i].sx;a[i].pjf=a[i].sum/3.0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%s %d %c %d %d %d %d %.1f\n",a[i].xm,a[i].xh,a[i].xb,a[i].yw,a[i].sx,a[i].yy,a[i].sum,a[i].pjf);
	}
	return 0;
}
