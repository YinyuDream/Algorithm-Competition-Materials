#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,top;
bool book[1000000];
int t[100000];
void Getp(int x)
{
	for(int i=2;i<=x;i++)
	{
		if(book[i]==false)t[++top]=i;
		for(int j=1;j<=top&&t[j]*i<=x;j++)
		{
			book[t[j]*i]=true;
			if(i%t[j]==0)break;
		}
	}
}
void Getans(int l,int r)
{
	memset(book,0,sizeof book);
	int cnt=0;
	for(int i=1;i<=top;i++)
	{
		if(book[i])continue;
		for(int j=(l-1)/t[i]+1;j*t[i]<=r;j++)
			book[j*t[i]]=true;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	Getp(sqrt(m));
	for(int i=1;i<=top;i++)
		t[i]*=t[i];
	Getans(n,m);
	for(int i=n;i<=m;i++)
		if(book[i]==0)
			printf("%d\n",i);
	return 0;
}
