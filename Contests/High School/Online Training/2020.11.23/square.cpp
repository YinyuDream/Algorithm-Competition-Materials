#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
const long long p=998244353;
long long n,m,ans;
long long gcd(long long x,long long y)
{
	return !y?x:gcd(y,x%y);
}
int not_prime[maxn],prime[maxn],cnt;
void get_prime()
{
	for(int i=2;i<maxn;i++){
		if(!not_prime[i]){
			prime[++cnt]=i;
		}
		for(int j=2;j<=cnt&&i*prime[j]<maxn;j++){
			not_prime[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int main(){
	//freopen("square.in","r",stdin);
	//freopen("square.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(n<m)swap(n,m);
	ans=((m-1)*m%p*(2*m-1)%p*(3*(m-1)*(m-1)%p+3*(m-1)-1)/30%p+(2-n-m)*m%p*m%p*(m-1)%p*(m-1)/4%p+(n*m-2*n-2*m+1)%p*(m-1)%p*m%p*(2*m-1)/6%p+(2*n*m-n-m)%p*m%p*(m-1)/2%p+m*m%p*n)%p;
    for(long long i=1;i<=n-1;i++)
        for(long long j=1;j<=m-i;j++)
            (ans+=(n-i-j+1)*(m-i-j+1)*(i*i+j*j-2*(i+j-gcd(i,j))))%=998244353;
    printf("%lld\n",ans);
    return 0;
}
