#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e7+10,N=8e4+10;
bool book[maxn];
int isp[N],top,ans[maxn];
void Getp1(int x)
{
	for(int i=2;i<=x;i++)
	{
		if(book[i]==0)isp[++top]=i;
		for(int j=1;j<=top&&i*isp[j]<=x;j++)
		{
			book[i*isp[j]]=true;
			if(i%isp[j]==0)break;
		}
	}
}
void Getp2(long long l,long long r)
{
	int cnt=0;
	for(int i=1;i<=top;i++)
		for(long long j=max((l-1)/isp[i]+1,2ll);j*isp[i]<=r;j++)
			book[isp[i]*j-l]=true;
	for(int i=l-l;i<=r-l;i++)
		if(book[i]==0&&i+l>1)
			cnt++;
	printf("%d",cnt);
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	Getp1(sqrt(n));
	memset(book,0,sizeof book);
	Getp2(m,n);
	return 0;
}
