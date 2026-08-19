#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int M=73; 
const int N=146;
ll a[N][N],b[N][N],ttt[N][N],c[N][N],sum[N][N],g[N][N];
ll dp[M][M][M*(M+1)/2][2],dp2[M][M][M*(M+1)/2][2],f[N][N*N];
ll tmp[2][N*N][2],h[N*N][2];
int nn;
void solve(int n,int gg)
{
	memset(sum,0,sizeof(sum));
	memset(g,0,sizeof(g));
	if (c[2][n]==-1) c[2][n]=-1e18;
	rep(i,0,nn+1) if (c[i][0]==-1) c[i][0]=0;
	rep(i,1,nn+1)
	  rep(j,0,nn+1)
	    sum[i][j]=sum[i-1][j]+c[i][j];
	dep(i,nn+1,1)
	  dep(j,nn+1,1)
	    g[i][j]=max(g[i+1][j],c[i][j]);
	ll to=0;
    rep(i,1,nn) to=max(to,c[i][0]); 
	rep(i,0,M-1)
	  rep(j,0,M-1)
	    rep(k,0,M*(M+1)/2-1)
	      rep(t,0,1)
	        dp[i][j][k][t]=dp2[i][j][k][t]=-1e18;
//    memset(dp,128,sizeof(dp)); memset(dp2,128,sizeof(dp2));
    dp[n+1][0][0][0]=0; 
    dep(j,n+1,n+1)
    	dep(i,n-j+2,0)
          dep(k,(n+4)*(n)/2,i) 
		    rep(tt,0,1)
			  dp2[j][i][k][tt]=max(dp[j][i][k][tt],dp2[j][i+1][k][tt]);
    dep(j,n,1)
    {
      rep(i,0,n-j+2)
          dep(k,(n-j+4)*(n-j+1)/2,i)
          {
            rep(tt,0,1)
              dp[j][i][k][tt]=max(dp[j][i][k][tt],dp2[j+1][max(i-1,0)][k-i][tt]+sum[i][j]);
            if (k-i-1>=0) dp[j][i][k][1]=max(dp[j][i][k][1],dp2[j+1][max(i-1,0)][k-i-1][0]+sum[i][j]+g[i+1][j]);
            if (i-2>=0)
            {
            	dp[j][i][k][1]=max(dp[j][i][k][1],dp[j+1][i-2][k-i][0]+sum[i][j]);
            }
		  }
		memset(f,128,sizeof(f));
		dep(k,(n-j+4)*(n-j+1)/2,0)
		  dep(i2,n-j+2,1)
		      f[i2][k]=max(f[i2+1][k],dp[j][i2][k][0]);
		dep(k,(n-j+4)*(n-j+1)/2,0)
		  dep(i2,n-j+2,1)
		    dep(i1,i2,1)
			   dp[j][i1-1][k][1]=max(dp[j][i1-1][k][1],f[i2][k+(i2-i1+1)]-(sum[i2][j]-sum[i1-1][j]));
	    dep(i,n-j+2,0)
          dep(k,(n+4)*(n)/2,i) 
		    rep(tt,0,1)
			  dp2[j][i][k][tt]=max(dp[j][i][k][tt],dp2[j][i+1][k][tt]);
	}
	if (gg==0)
	{
		dep(j,0,0)
		  rep(i2,3,n-j+1)
		    rep(i1,3,i2) 
		    dep(k,(n-j+4)*(n-j+1)/2,i2-i1+1)
		    {
		    	dp[j][i2][k][1]=max(dp[j][i2][k][1],dp2[j+1][max(i2-1,0)][k-(i2-i1+1)][0]+sum[i2][j]-sum[i1-1][j]);
		    }
    } else
    {
		dep(j,0,0)
		  rep(i2,2,n-j+1)
		    rep(i1,2,i2)
		    dep(k,(n-j+4)*(n-j+1)/2,i2-i1+1)
		    {
		    	dp[j][i2][k][1]=max(dp[j][i2][k][1],dp2[j+1][max(i2-1,0)][k-(i2-i1+1)][0]+sum[i2][j]-sum[i1-1][j]);
		    }
    }
    dep(j,0,0)
      rep(i,0,n-j+1)
        rep(k,1,(M*M)/2)
            dp[j][i][k][1]=max(dp[j][i][k][1],dp[j+1][i][k-1][0]+to);
	rep(i,0,n+3)
	  rep(j,1,(M*M)/2)
	    rep(tt,0,1) 
	      tmp[gg][j][tt]=max({tmp[gg][j][tt],dp[0][i][j][tt],dp[1][i][j][tt]});
}
signed main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	rep(i,0,1)
	  rep(j,1,N*N-1)
	    rep(k,0,1) tmp[i][j][k]=-1e18;
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	nn=n;
	rep(i,1,n)
	  rep(j,1,n) cin>>a[i][j];
	memset(c,-1,sizeof(c));
	rep(i,1,n) b[1][i]=1;
	rep(i,2,n)
	  rep(j,2,n-1)
	    b[i][j]=b[i-1][j-1]&b[i-1][j+1];
	int mx=0;
	rep(i,1,n)
	  rep(j,1,n)
	    if ((i+j)%2==0&&b[i][j]) mx=max(mx,i);
	rep(i,1,n)
	  rep(j,1,n)
	    if ((i+j)%2==0&&(j-i)/2+1>=0&&(j-i)/2+1+i<=mx+2)
	    {
	    	ttt[i][j]=1;
	    	c[i][(j-i)/2+1]=a[i][j];
	    }
	solve(mx,0);
	int n1=mx; memset(c,-1,sizeof(c));
	mx=0;
	rep(i,1,n)
	  rep(j,1,n)
	    if ((i+j)%2==1&&b[i][j])
	    {
	      mx=max(mx,i);
	    }
	rep(i,1,n)
	  rep(j,1,n)
	    if ((i+j)%2==1&&(j-i-1)/2+1>=0&&(j-i-1)/2+1+i<=mx+2)
	    {
	      ttt[i][j]=1;
	      c[i][(j-i-1)/2+1]=a[i][j];
	    }
	solve(mx,1);
	int n2=mx;
	mx=0;
	rep(i,1,n)
	  rep(j,1,n)
	    if (!ttt[i][j]) mx=max(mx,(int)a[i][j]);
	memset(h,128,sizeof(h));
	rep(i,0,n1*(n1+3)/2) 
	  rep(j,0,n2*(n2+3)/2)
	    rep(t1,0,1)
	      rep(t2,0,1)
	        if (t1+t2<=1) 
	          h[i+j][t1+t2]=max(h[i+j][t1+t2],tmp[0][i][t1]+tmp[1][j][t2]);
    rep(i,0,n*n)
      h[i+1][1]=max(h[i][0]+mx,h[i+1][1]);
	rep(i,1,n*n) h[i][1]=max(h[i][1],h[i][0]);
	rep(i,1,n*n) if (h[i][k]>=0) cout<<h[i][k]<<endl; else cout<<-1<<endl;
	return 0;
}
