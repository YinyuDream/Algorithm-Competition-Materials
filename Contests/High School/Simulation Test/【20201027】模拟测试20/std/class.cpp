/*"Level Of ViolencE"*/
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
typedef double D;
typedef pair<int,int> Pii;
#define mp(a,b) make_pair(a,b)
#define fir first
#define sec second
#define I inline
#define R register
inline int min(int _a,int _b){return _a<_b?_a:_b;}
inline int max(int _a,int _b){return _a>_b?_a:_b;}
template<class T>inline void rd(T &_a){
	int _f=0,_ch=getchar();_a=0;
	while(_ch<'0' || _ch>'9'){if(_ch=='-')_f=1;_ch=getchar();}
	while(_ch>='0' && _ch<='9'){_a=(_a<<1)+(_a<<3)+_ch-'0';_ch=getchar();}
	if(_f)_a=-_a;
}
const int inf=0x3f3f3f3f;
const D eps=1e-8;
const int N=1e5+5;
struct node{int l,r,sz;LL s,mx;}t[N<<4];
struct pt{
	int s,cnt,num,mx,mn;
	bool operator <(const pt &a)const{return s<a.s;}
}pp[N];
int ef[N],root[50],idx,cnt,n;
I void Ud(int &rt,int l,int r,int p,int x){
	if(!rt)rt=++idx;
	if(l==r){
		t[rt].s=t[rt].mx=x;
		t[rt].sz=1;
		return;
	}
	int m=l+r>>1;
	if(p<=m)Ud(t[rt].l,l,m,p,x);
	else Ud(t[rt].r,m+1,r,p,x);
	t[rt].s=t[t[rt].l].s+t[t[rt].r].s;
	t[rt].sz=t[t[rt].l].sz+t[t[rt].r].sz;
	t[rt].mx=max(t[t[rt].l].mx,t[t[rt].r].mx);
}
I LL Qy(int rt,int l,int r,int lp,int rp,int x){
	if(l==lp && r==rp)
		return x?t[rt].mx:(cnt+=t[rt].sz,t[rt].s);
	int m=l+r>>1;
	if(rp<=m)return Qy(t[rt].l,l,m,lp,rp,x);
	if(lp>m)return Qy(t[rt].r,m+1,r,lp,rp,x);
	LL r1=0,r2=0;
	if(t[rt].l)r1=Qy(t[rt].l,l,m,lp,m,x);
	if(t[rt].r)r2=Qy(t[rt].r,m+1,r,m+1,rp,x);
	return x?max(r1,r2):r1+r2;
}
I LL clac(int s,int x){
	if(!x)return x;
	s%=(abs(x)+1)*2;
	return (abs(x)-abs(abs(x)-s))*(x/abs(x));
}
I int findl(int x){
	int l=0,r=n-1,ans;
	while(l<=r){
		int mid=l+r>>1;
		if(pp[mid].s>=x)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
I int findr(int x){
	int l=0,r=n-1,ans;
	while(l<=r){
		int mid=l+r>>1;
		if(pp[mid].s<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main(){
	//clock_t start=clock();
	freopen("PE.in","r",stdin);
	freopen("PE.out","w",stdout);
	puts("IA");
	ef[0]=-1e9-5;
	int m;rd(n);rd(m);
	for(R int i=1;i<=n;i++){
		rd(pp[i].s);rd(pp[i].mn);rd(pp[i].mx);rd(pp[i].num);
		pp[i].cnt=i;pp[i].num=pp[i].num?-1:1;
	}
	sort(pp+1,pp+n+1);
	for(R int i=1;i<=n;i++)
		ef[i]=pp[i].s,Ud(root[(pp[i].mx-pp[i].mn)*pp[i].num+13],1,n,i,pp[i].num==1?pp[i].mn:pp[i].mx);
	for(R int i=0;i<m;i++){
		int op,s,l,r;
		rd(op);rd(s);rd(l);rd(r);
		l=lower_bound(ef,ef+n+1,l)-ef;
		r=upper_bound(ef,ef+n+1,r)-ef-1;
		if(l>r){puts("-1");continue;}
		LL ans=0;
		for(R int j=0;j<27;j++)
			if(op)ans=max(ans,Qy(root[j],1,n,l,r,op)+clac(s,j-10));
			else cnt=0,ans+=Qy(root[j],1,n,l,r,op)+clac(s,j-10)*cnt;
		printf("%lld\n",ans);
	}
	//printf("\n%dms",(int)((double)(clock()-start)/CLOCKS_PER_SEC*1000));
	return 0;
}

