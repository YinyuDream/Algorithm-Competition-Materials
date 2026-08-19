#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e6+10;
int n,ans;
int sum[maxn],prime[maxn],not_prime[maxn],cnt;
void get_prime()
{
	for(int i=2;i<maxn;i++)
	{
		if(!not_prime[i])prime[++cnt]=i;
		for(int j=1;prime[j]*i<maxn;j++)
		{
			not_prime[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
	}
}
int num[maxn],p[maxn],top;
void work(int x)
{
	top=0;
	int t=sqrt(x)+1;
	for(int i=1;prime[i]<=t;i++){
		if(x%prime[i]==0){
			p[++top]=prime[i];
			num[top]=0;
			while(x%prime[i]==0){
				num[top]++;
				x/=prime[i];
			}
		}
	}
	if(x!=1){
		p[++top]=x;
		num[top]=1;
	}
}
void dfs_add(int pos,int val)
{
	
	if(pos==top+1){
		sum[val]++;
		return ;
	}
	for(int i=0,pval=1;i<=num[pos];i++){
		dfs_add(pos+1,val*pval);
		pval*=p[pos];
	}
}
int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	scanf("%d",&n);
	get_prime();
	for(int i=1,opt,x;i<=n;i++){
		scanf("%d%d",&opt,&x);
		if(opt==1){
			work(x);
			dfs_add(1,1);
		}else if(opt==2){
			ans^=sum[x];
		}
	}
	printf("%d",ans);
	return 0;
}
