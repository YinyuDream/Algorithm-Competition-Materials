#include<cstdio>
#include<cstring>
using namespace std;
const int p=1e9+7,N=1e2+1; 
long long n,k;
struct node{
	long long map[N][N];
	node(){
		memset(map,0,sizeof map);
	}
	void Make_e(){
		for(int i=1;i<=n;i++)
			map[i][i]=1;
	}
	void pt(){
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%d ",map[i][j]%p);
			puts("");
		}
	}
}e,t;
node operator*(node a,node b)
{
	node c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				c.map[i][j]=(c.map[i][j]%p+(a.map[i][k]%p)*(b.map[k][j]%p)%p)%p;
	return c;
				
}
node quick(node a,long long x)
{
	if(x==0)return e;
	if(x==1)return a;
	node ans=quick(a,x/2);
	if(x&1)return ans*ans*a;
	else return ans*ans;
}
int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&t.map[i][j]);
	e.Make_e();
	t=quick(t,k);
	t.pt();
}
