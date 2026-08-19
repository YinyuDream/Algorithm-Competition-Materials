#include<cstdio>
using namespace std;
const int maxn=2e6+10;
int n;
int prime[maxn],not_prime[maxn],phi[maxn],cnt;
long long ans;
void get_phi()
{
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!not_prime[i]){
			prime[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*prime[j]>n)break;
			not_prime[i*prime[j]]=true;
			if(i%prime[j]!=0)
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
			else
			phi[i*prime[j]]=phi[i]*prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
	scanf("%d",&n);
	get_phi();
	for(int i=1;i<=n;i++)
		ans+=1ll*phi[i]*(n/i)*(n/i);
	printf("%lld",(ans-1ll*n*(n+1)/2)/2);
	return 0;
}
