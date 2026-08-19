#include<cstdio>
using namespace std;
const int maxn=100010+10;
int n;
int cnt1,cnt2,cnt3;
int a[maxn];
int minn=1;
int min(int x,int y)
{
	if(x>y)return y;
	else return x;
}
int main()
{
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[minn]>a[i])minn=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=minn)
		{
			int temp=a[i]-a[minn];
			cnt1+=temp/5;
			temp=temp%5;	
			cnt1+=temp/2;
			temp=temp%2;
			cnt1+=temp/1;
		}
	}
	a[minn]--;
	cnt2++;
	for(int i=1;i<=n;i++)
	{
		if(i!=minn)
		{
			int temp=a[i]-a[minn];
			cnt2+=temp/5;
			temp=temp%5;	
			cnt2+=temp/2;
			temp=temp%2;
			cnt2+=temp/1;
		}
	}
	a[minn]--;
	cnt3++;
	for(int i=1;i<=n;i++)
	{
		if(i!=minn)
		{
			int temp=a[i]-a[minn];
			cnt3+=temp/5;
			temp=temp%5;	
			cnt3+=temp/2;
			temp=temp%2;
			cnt3+=temp/1;
		}
	}
	printf("%d",min((min(cnt1,cnt2)),cnt3));
	return 0;
}

