#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1e4+10;
int p[maxn],t[maxn],top,n;
bool book[maxn];
void Getp()
{
	for(int i=2;i<=n;i++)
	{
		if(book[i]==0)t[++top]=i;
		for(int j=1;j<=top&&i*t[j]<=n;j++)
		{
			book[i*t[j]]=true;
			if(i%t[j]==0)break;
		}
	}
}
int main(){
	scanf("%d",&n);
	Getp();
	for(int i=1;i<=top;i++)
	{
		for(int j=1;pow(t[i],j)<=n;j++)
		{
			p[t[i]]+=n/pow(t[i],j);
		}
	}
	for(int i=1;i<=top;i++)
		printf("%d %d\n",t[i],p[t[i]]);
	return 0;
}
