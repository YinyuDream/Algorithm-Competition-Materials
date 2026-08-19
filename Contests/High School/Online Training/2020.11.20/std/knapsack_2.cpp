#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxq 100005
#define maxn 20005
#define maxm 505
#define maxp 15
#define mo 998244353
using namespace std;

int n,q,i,j,k,v[maxn],w[maxn],m;
int que[maxq][3],ans[maxq],ans0[maxq],d[maxp][maxq],D[maxq];
int f[maxn][maxm],g[maxn][maxm];

void clear(int i){
	memset(f[i],0,sizeof(f[i]));
	memset(g[i],0,sizeof(g[i]));
	g[i][0]=1;
}

void dp(int i,int k){
	for(int j=0;j<=m;j++)
		if (j<w[i]) f[i][j]=f[k][j],g[i][j]=g[k][j]; else {
			f[i][j]=max(f[k][j],f[k][j-w[i]]+v[i]);
			g[i][j]=(f[i][j]==f[k][j])*g[k][j]
				   +(f[i][j]==f[k][j-w[i]]+v[i])*g[k][j-w[i]];
			g[i][j]%=mo;
		}
}

void merge(int l,int r,int t){
	if (!d[t][0]) return;
	if (l==r){
		for(int i=1;i<=d[t][0];i++){
			int k=d[t][i];
			if (que[k][2]>=w[l])
				ans[k]=v[l],ans0[k]=1;
		}
		return;
	}
	int mid=(l+r)>>1;
	d[t+1][0]=0;
	for(int i=1;i<=d[t][0];i++) if (que[d[t][i]][1]<=mid)
		d[t+1][++d[t+1][0]]=d[t][i];
	merge(l,mid,t+1);
	d[t+1][0]=0;
	for(int i=1;i<=d[t][0];i++) if (que[d[t][i]][0]>mid)
		d[t+1][++d[t+1][0]]=d[t][i];
	merge(mid+1,r,t+1);
	D[0]=0;
	for(int i=1;i<=d[t][0];i++) if (que[d[t][i]][1]>mid&&que[d[t][i]][0]<=mid)
		D[++D[0]]=d[t][i];
	if (!D[0]) return;
	for(int i=mid;i>=l;i--){
		clear(i);
		if (i==mid) f[i][w[i]]=v[i],g[i][w[i]]=1; 
			else dp(i,i+1);
	}
	for(int i=mid+1;i<=r;i++){
		clear(i);
		if (i==mid+1) f[i][w[i]]=v[i],g[i][w[i]]=1;
			else dp(i,i-1);
	}
	while (D[0]){
		int k=D[D[0]--],L=que[k][0],R=que[k][1],M=que[k][2],mxr=0,mxr0;
		for(int i=M;i>=0;i--) 
			mxr=max(mxr,f[R][M-i]),ans[k]=max(ans[k],f[L][i]+mxr);
		mxr=mxr0=0;
		for(int i=M;i>=0;i--){
			if (f[R][M-i]==mxr) (mxr0+=g[R][M-i])%=mo;
			else if (f[R][M-i]>mxr) mxr=f[R][M-i],mxr0=g[R][M-i];
			if (f[L][i]+mxr==ans[k])
				(ans0[k]+=1ll*g[L][i]*mxr0%mo)%=mo;
		}
	}
}

int main(){
//	freopen("ceshi.in","r",stdin);
//	freopen("ceshi.out","w",stdout);
	freopen("knapsack.in","r",stdin);
	freopen("knapsack.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d",&v[i],&w[i]);
	scanf("%d",&q);
	for(i=1;i<=q;i++) scanf("%d%d%d",&que[i][0],&que[i][1],&que[i][2]),m=max(m,que[i][2]);
	for(i=1;i<=q;i++) d[0][++d[0][0]]=i;
	merge(1,n,0);
	for(i=1;i<=q;i++) if (ans[i]==0) printf("0 0\n"); else printf("%d %d\n",ans[i],ans0[i]);
}
