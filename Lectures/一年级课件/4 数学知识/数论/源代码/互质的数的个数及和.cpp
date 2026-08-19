#include<cstdio>
const int maxn=1e8+10;
using namespace std;
int n;
int f[maxn],p[maxn],top,sum[maxn];
bool book[maxn];
void Getp()
{
	for(int i=2;i<=n;i++)
	{
		if(book[i]==0)p[++top]=i,f[i]=i-1;
		for(int j=1;j<=top&&i*p[j]<=n;j++)
		{
			if(i%p[j]!=0)book[i*p[j]]=true,f[i*p[j]]=f[i]*(p[j]-1);
			else {
				book[i*p[j]]=true;
				f[i*p[j]]=f[i]*p[j];
				break;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	Getp();
	for(int i=1;i<=n;i++)
		sum[i]=(f[i]*i)/2;
	for(int i=1;i<=n;i++)
		printf("%d %d\n",f[i],sum[i]);
	return 0;
}
