#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=1e4+10;
int n;
int not_prime[maxn],prime[maxn],ans[maxn],cnt;
void get_prime()
{
	for(int i=2;i<=n;i++){
		if(!not_prime[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=n;j++){
			not_prime[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
}
void dfs(int pos,int &limit)
{
	if(pos==n+1){
		printf("%d\n",limit);
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		exit(0);
	}
	for(int i=1;i<=limit;i++){
		bool flag=1;
		for(int j=1;j<=cnt&&pos-prime[j]>0;j++)
			if(ans[pos-prime[j]]==i)
				flag=0;
		if(flag)ans[pos]=i,dfs(pos+1,limit);
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&n);
	get_prime();
	for(int i=1;i<=n;i++)
		dfs(1,i);
}
