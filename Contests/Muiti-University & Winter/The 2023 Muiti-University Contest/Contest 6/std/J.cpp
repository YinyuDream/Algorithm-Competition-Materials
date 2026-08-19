#include <bits/stdc++.h>
#define rep(i,h,t) for(int i=h;i<=t;i++)
using namespace std;
#define mid ((h+t)/2)
const int N=8e6;
const int M=5e5;
int rt1[M],rt2[M],a[M];
struct re{
	int a,b,c;
};
struct sgt{
	int cnt;
	int sum[N],ls[N],rs[N];
	void g(int &x,int h,int t,int pos,int k)
	{
		int lst=x; x=++cnt; sum[x]=sum[lst]+k; ls[x]=ls[lst]; rs[x]=rs[lst];
		if (h==t) return;
		if (pos<=mid) g(ls[x],h,mid,pos,k);
		else g(rs[x],mid+1,t,pos,k);
	}
	re q(int x,int y,int h,int t,int k)
	{
		if (h==t) return {h,k,sum[y]-sum[x]};
		if (sum[rs[y]]-sum[rs[x]]>=k) return q(rs[x],rs[y],mid+1,t,k);
		else return q(ls[x],ls[y],h,mid,k-(sum[rs[y]]-sum[rs[x]]));
	}
	int q2(int x,int y,int h,int t,int h1,int t1)
	{
		int ans=0;
		if (sum[y]-sum[x]==0) return 0;
		if (h==t) return h;
		if (mid<t1) ans=q2(rs[x],rs[y],mid+1,t,h1,t1);
		if (!ans)
		{
			if (h1<=mid) ans=q2(ls[x],ls[y],h,mid,h1,t1);
		}
		return ans;
	}
}S1,S2;
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout); 
	ios::sync_with_stdio(false);
	int n,q; 
	cin>>n>>q;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n)
	{
		int t=a[i]; rt1[i]=rt1[i-1]; rt2[i]=rt2[i-1];
		while (t%2==0)
		{
			S1.g(rt1[i],1,1e9,t,1);
			t/=2;
		}
		while (t)
		{
			int k=t,cnt=1; t/=2;
			while (t%2==0&&t)
			{
				t/=2; cnt++;
			}
			S2.g(rt2[i],1,1e9,k,cnt);
		}
	}
	while (q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		if (S1.sum[rt1[r]]-S1.sum[rt1[l-1]]>=k)
		{
			re x={0,0,0};
			if (S1.sum[rt1[r]]-S1.sum[rt1[l-1]]!=k)
			  x=S1.q(rt1[l-1],rt1[r],1,1e9,k+1);
			int y=S2.q2(rt2[l-1],rt2[r],1,1e9,1,1e9);
			cout<<max(x.a,y)<<endl;
		} else
		{
			k-=S1.sum[rt1[r]]-S1.sum[rt1[l-1]];
			if (S2.sum[rt2[r]]-S2.sum[rt2[l-1]]<=k)
			{
				cout<<0<<endl;
				continue;
			}
			re y=S2.q(rt2[l-1],rt2[r],1,1e9,k);
			int t=0;
			if (y.a-1>0) t=S2.q2(rt2[l-1],rt2[r],1,1e9,1,y.a-1);
			int gg=y.a;
			gg/=2; int cnt=1;
			while (gg%2==0&&gg) gg/=2,cnt++;
			if (y.c-y.b<cnt)
			{
			    int k=(y.b-1)%cnt+1;
			    int q=y.a;
			    rep(i,1,k) q/=2; 
				t=max(t,q);
			} else t=y.a;
			cout<<t<<endl;
		}
	}
	return 0;
}
