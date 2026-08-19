#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e7+10;
int n,cnt,q;
bool book[maxn];
int top,isp[5761456];
void Getp_N()
{
	for(int i=2;i<=n;i++)
	{
		if(book[i]==0)isp[++top]=i;
		for(int j=1;j<=top&&i*isp[j]<=n;j++)
		{
			book[i*isp[j]]=true;
			if(i%isp[j]==0)break;
		}
	}
	book[0]=book[1]=1;
	for(int i=1;i<=q;i++)
	{
		int p;
		scanf("%d",&p);
		if(book[p]==0)puts("Yes");
		else puts("No");
	}
}
int main(){
	scanf("%d%d",&n,&q);
	Getp_N();
	return 0;
}
