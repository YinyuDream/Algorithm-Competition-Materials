#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,ans,mx,a[maxn];
int book[maxn][maxn];
int main(){
	freopen("trouble.in","r",stdin);
	freopen("trouble.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		mx=max(mx,a[i]);
	for(int i=1;i<n;i++){
		int cnt=0;
		for(int j=1;j<=mx*3;j++){
			if(book[i-1][j]==0)
				book[i][j]=1,cnt++,ans=max(ans,j);
			if(cnt==a[i])break;
		}
	}
	for(int i=1,cnt=0;i<=mx*3;i++){
		if(book[n-1][i]==0&&book[1][i]==0)
			book[n][i]=1,cnt++,ans=max(ans,i);
		if(cnt==a[n])break;
	}
	printf("%d",ans);
	return 0;
}
