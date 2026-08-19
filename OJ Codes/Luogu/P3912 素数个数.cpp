#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e8+10;
int n,cnt;
bool book[maxn];
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
}
void Getp_N()
{
	for(int i=2;i<=n;i++)
	{
		if(book[i]==0)isp[++top]=i,cnt++;
		for(int j=1;j<=top&&i*isp[j]<=n;j++)
		{
			book[i*isp[j]]=true;
			if(i%isp[j]==0)break;
		}
	}
	//for(int i=1;i<=top;i++)
		//printf("%d\n",isp[i]);
}
int main(){
	scanf("%d",&n);
	//Getp_NloglogN();
	Getp_N();
	printf("%d",cnt);
	return 0;
}