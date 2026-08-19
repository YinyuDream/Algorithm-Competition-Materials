#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,cnt1,cnt2,ans;
struct seg{
	int c,l,r;
}a[maxn],b[maxn];
int mapp[maxn][maxn],use[maxn],result[maxn];
bool dfs(int x)
{
	for(int i=1;i<=cnt2;i++){
		if(mapp[x][i]&&!use[i]){
			use[i]=1;
			if(!result[i]||dfs(result[i])){
				result[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1,_a,_b,_c,_d;i<=n;i++){
		scanf("%d%d%d%d",&_a,&_b,&_c,&_d);
		if(_a==_c)a[++cnt1]={_a,_b,_d};
		if(_b==_d)b[++cnt2]={_b,_a,_c};
	}
	for(int i=1;i<=cnt1;i++)
		if(a[i].l>a[i].r)
			swap(a[i].l,a[i].r);
	for(int i=1;i<=cnt2;i++)
		if(b[i].l>b[i].r)
			swap(b[i].l,b[i].r);
	for(int i=1;i<=cnt1;i++){
		for(int j=1;j<=cnt2;j++){
			if(a[i].l<=b[j].c&&a[i].r>=b[j].c&&b[j].l<=a[i].c&&b[j].r>=a[i].c){
				mapp[i][j]=1;
			}
		}
	}
	for(int i=1;i<=cnt1;i++){
		memset(use,0,sizeof use);
		if(dfs(i))ans++;
	}
	printf("%d",n-ans);
	return 0;
}
