#include<cstdio>
const int maxn=1e6+10;
int T;
int not_prime[maxn],phi[maxn],prime[maxn],cnt;
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,
	ch=getchar();
	return x;
}
void get_phi()
{
	phi[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!not_prime[i]){
			prime[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*prime[j]>=maxn)break;
			not_prime[i*prime[j]]=true;
			if(i%prime[j]!=0)
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
			else
			phi[i*prime[j]]=phi[i]*prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
int main()
{
	scanf("%d",&T);
	get_phi();
	while(T--)
		printf("%d\n",phi[read()]);
}
