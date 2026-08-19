#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=100000+10;
int n;
int a[maxn];
int cnt1=0,cnt2=1,cnt3=1,ans;
int main()
{
	//freopen("queue.in","r",stdin);
	//freopen("queue.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);//从小到大排序。 
	for(int i=2;i<=n;i++)
	{
		ans=a[i]-a[1];
		cnt1+=ans/5;
		ans%=5;
		cnt1+=ans/2;
		ans%=2;
		if(ans>0)cnt1++;
	}
	a[1]--;
	for(int i=2;i<=n;i++)
	{
		ans=a[i]-a[1];
		cnt2+=ans/5;
		ans%=5;
		cnt2+=ans/2;
		ans%=2;
		if(ans>0)cnt2++;
	}
	a[1]--;
	for(int i=2;i<=n;i++)
	{
		ans=a[i]-a[1];
		cnt3+=ans/5;
		ans%=5;
		cnt3+=ans/2;
		ans%=2;
		if(ans>0)cnt3++;
	}
	if(cnt1>cnt2)cnt1=cnt2;
	if(cnt1>cnt3)cnt1=cnt3;
	printf("%d",cnt1);
	return 0;
}
