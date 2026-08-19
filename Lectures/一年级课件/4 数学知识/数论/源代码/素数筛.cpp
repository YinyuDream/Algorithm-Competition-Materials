#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn=1e8+10;
int n,cnt;
bool book[maxn],q;
int top,isp[5761456];
void Getp_NloglogN()
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(book[i])continue;
		for(int j=i;j*i<=n;j++)
		{
			book[i*j]=true;
		}
	}
	for(int i=2;i<=n;i++)
		if(book[i]==0)
			cnt++,printf("%d\n",i);
	printf("%d",cnt);
}
void Getp_N()
{
	for(int i=2;i<=n/2;i++)
	{
		if(book[i]==0)isp[++top]=i;
		for(int j=1;j<=top&&i*isp[j]<=n;j++)
		{
			book[i*isp[j]]=true;
			if(i%isp[j]==0)break;
		}
	}
	for(int i=2;i<=n;i++)
		if(book[i]==0)cnt++;
	printf("%d\n",cnt);
}
int main(){
	scanf("%d",&n);
	srand((unsigned)time(0));
	int k=rand()%2;
	if(k==0)Getp_NloglogN();
	else Getp_N();
	return 0;
}
