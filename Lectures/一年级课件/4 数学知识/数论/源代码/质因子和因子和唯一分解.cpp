#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e8+10;
int n;
int p[maxn],top;
bool book[maxn];
int k[maxn],t,s,q[maxn];
void Getp(int x)
{
	for(int i=2;i<=x;i++)
	{
		if(book[i]==0)p[++top]=i;
		for(int j=1;i*p[j]<=x&&j<=top;j++)
		{
			book[i*p[j]]=true;
			if(i%p[j]==0)break;
		}
	}
}
void divide()
{
	int m=n; 
	while((++t)<=top)
	{
		if(n%p[t]==0)k[++s]=p[t];
		while(n%p[t]==0&&n!=0)n/=p[t],q[s]++;
	}
	if(n!=1)k[++s]=n,q[s]=1;
	for(int i=1;i<=s;i++)
		printf("第%d个质因数是:%d\n",i,k[i]);
	printf("唯一分解:"); 
	for(int i=1;i<s;i++)printf("%d^%d*",k[i],q[i]);
	printf("%d^%d\n",k[s],q[s]);
	memset(k,0,sizeof k);s=0;
	for(int i=1;i<=sqrt(m);i++)
	{
		if(m%i==0){
			k[++s]=i;
			k[++s]=m/i;
		}
	}
	if(k[s]==(int)sqrt(m))s--;
	sort(k+1,k+s+1);
	for(int i=1;i<=s;i++)
		printf("第%d个因数是:%d\n",i,k[i]);
}

int main(){
	scanf("%d",&n);
	Getp(sqrt(n));
	divide();
	return 0;
}
