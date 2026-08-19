#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5e3+10;
int T,n,l,r;
int mapp[maxn][maxn],use[maxn],result[maxn];
bool dfs(int x,int top)
{
	for(int i=1;i<=top;i++){
		if(mapp[x][i]&&!use[i]){
			use[i]=1;
			if(!result[i]||dfs(result[i],top)){
				result[i]=x;
				return true;
			}
		}
	}
	return false;
}
void pre()
{
	for(int i=1;i<maxn;i++){
		for(int j=1;j*j-i<maxn;j++){
			if(j*j-i>i){
				mapp[i][j*j-i]=1;
			}
		}
	}
}
bool check(int x)
{
	memset(use,0,sizeof use);
	memset(result,0,sizeof result);
	int ans=0;
	for(int i=1;i<=x;i++)
		if(dfs(i,x))
			ans++,memset(use,0,sizeof use);
	return x-ans<=n;		
}
int main(){
	scanf("%d",&T);
	pre();
	while(T--){
		l=1,r=maxn-1;
		scanf("%d",&n);
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid))l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",r);
	}
	return 0;
}
