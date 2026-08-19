#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+10,maxm=510,p=998244353;
int n,m,k;
int w[maxn],v[maxn];
struct node{
	int l,r,lim,cnt,val;
}q[maxn];
int lf[maxn][maxm],rf[maxn][maxm],lg[maxn][maxm],rg[maxn][maxm];
void solve(int l,int r)
{
	if(l==r)return ;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	memset(lf,0,sizeof lf);
	memset(rf,0,sizeof rf);
	memset(lg,0,sizeof lg);
	memset(rg,0,sizeof rg);
	for(int i=0;i<=m;i++)
	lg[mid+1][i]=rg[mid][i]=1;
	for(int i=mid;i>=l;i--){
		for(int j=0;j<=m;j++){
			lf[i][j]=lf[i+1][j];
			lg[i][j]=lg[i+1][j];
			if(j-v[i]>=0){
				if(lf[i+1][j-v[i]]+w[i]>lf[i][j]){
					lf[i][j]=lf[i+1][j-v[i]]+w[i];
					lg[i][j]=lg[i+1][j-v[i]];
				}else if(lf[i+1][j-v[i]]+w[i]==lf[i][j]){
					lg[i][j]+=lg[i+1][j-v[i]];
				}
			}
		}
	}
	for(int i=mid+1;i<=r;i++){
		for(int j=0;j<=m;j++){
			rf[i][j]=rf[i-1][j];
			rg[i][j]=rg[i-1][j];
			if(j-v[i]>=0){
				if(rf[i-1][j-v[i]]+w[i]>rf[i][j]){
					rf[i][j]=rf[i-1][j-v[i]]+w[i];
					rg[i][j]=rg[i-1][j-v[i]];
				}else if(rf[i-1][j-v[i]]+w[i]==rf[i][j]){
					rg[i][j]+=rg[i-1][j-v[i]];
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(q[i].l<=mid&&q[i].r>mid&&q[i].l>=l&&q[i].r<=r){
			for(int j=0;j<=q[i].lim;j++){
				if(lf[q[i].l][j]+rf[q[i].r][q[i].lim-j]>q[i].val){
					q[i].val=lf[q[i].l][j]+rf[q[i].r][q[i].lim-j];
					q[i].cnt=lg[q[i].l][j]*rg[q[i].r][q[i].lim-j];
				}else if(lf[q[i].l][j]+rf[q[i].r][q[i].lim-j]==q[i].val){
					q[i].cnt+=lg[q[i].l][j]*rg[q[i].r][q[i].lim-j];
				}
			}
		}
	}
}
int main(){
	//freopen("knapsack.in","r",stdin);
	//freopen("knapsack.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&v[i]);
		m=max(m,v[i]);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].lim);
	for(int i=1;i<=k;i++)
		if(q[i].l==q[i].r)
			if(v[q[i].l]<=q[i].lim)
				q[i].cnt=1,q[i].val=w[q[i].l];
	solve(1,n);
	for(int i=1;i<=k;i++)
		printf("%d %d\n",q[i].val,q[i].cnt);
	return 0;
}
