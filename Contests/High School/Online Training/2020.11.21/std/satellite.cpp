using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define N 200005
#define INF 1000000000
#define ll long long
const int sq=100000;
int n,m,mo,a,b;
ll qpow(ll x,ll y){
	ll r=1;
	for (;y;y>>=1,x=x*x%mo)
		if (y&1)
			r=r*x%mo;
	return r;
}
struct Pow{
	ll v,pw0[sq+1],pw1[sq+1];
	void init(ll _v){
		v=_v;
		pw0[0]=1;
		for (int i=1;i<=sq;++i)
			pw0[i]=pw0[i-1]*v%mo;
		pw1[0]=1;
		for (int i=1;i<sq;++i)
			pw1[i]=pw1[i-1]*pw0[sq]%mo;
	}
	ll ask(int x){
//		return qpow(v,x);
		return pw1[x/sq]*pw0[x%sq]%mo;
	}
} A,B;
ll ans[N];
struct DOT{int x,y,h;} p[N];
bool cmpp(DOT a,DOT b){return a.x<b.x;}
struct query{int x,y,id;} q[N];
bool cmpq(query a,query b){return a.x<b.x;}
void rot(int &x,int &y){
	int tmp=y;
	y=INF-x+1;
	x=tmp;
}
map<pair<int,int>,int> ma;
void work_(){
	for (int i=1;i<=n;++i)
		(ma[make_pair(p[i].x,p[i].y)]+=p[i].h)%=mo;
	for (int i=1;i<=m;++i){
		auto p=ma.find(make_pair(q[i].x,q[i].y));
		if (p!=ma.end())
			(ans[q[i].id]+=p->second)%=mo;
	}
}
struct Node{
	Node *l,*r;
	int len,s,tag;
	void gt(int c){
		s=(ll)s*c%mo;
		tag=(ll)tag*c%mo;
	}
	void pd(){
		if (tag!=1){
			l->gt(tag);
			r->gt(tag);
			tag=1;
		}
	}
	void upd(){
		s=(l->s*B.ask(len>>1)+r->s)%mo;
	}
} d[N*20],*null,*rt;
int cnt;
Node *newnode(int len){return &(d[++cnt]={null,null,len,0,1});}
void insert(int x,int c,Node *&t=rt,int l=1,int r=INF){
	if (t==null)
		t=newnode(r-l+1);
	if (l==r){
		(t->s+=c)%=mo;
		return;
	}
	t->pd();
	int mid=l+r>>1;
	if (x<=mid) insert(x,c,t->l,l,mid);
	else insert(x,c,t->r,mid+1,r);
	t->upd();
}
int res;
void query(int x,Node *t=rt,int l=1,int r=INF){
	if (l==r) return;
	int mid=l+r>>1;
	t->pd();
	if (x<=mid)
		query(x,t->l,l,mid);
	else{
		res=(res*B.ask(mid-l+1)+t->l->s)%mo;
		query(x,t->r,mid+1,r);
	}
}
void init(){
	null=d;
	*null={null,null,0,0,0};
	cnt=0;
	rt=newnode(INF);
}
void work(){
	A.init(a),B.init(b);
	sort(p+1,p+n+1,cmpp);
	sort(q+1,q+m+1,cmpq);
	init();
	int X=0;
	for (int i=1,j=1;i<=m;++i){
		for (;j<=n && p[j].x<=q[i].x;++j){
			rt->gt(A.ask(p[j].x-X)),X=p[j].x;
			insert(p[j].y,p[j].h);
		}
		rt->gt(A.ask(q[i].x-X)),X=q[i].x;
		res=0;
		query(q[i].y,rt);
		(ans[q[i].id]+=(ll)res*b)%=mo;
	}
	for (int i=1;i<=n;++i)
		rot(p[i].x,p[i].y);
	for (int i=1;i<=m;++i)
		rot(q[i].x,q[i].y);
	swap(a,b);
}
int main(){
	freopen("satellite.in","r",stdin);
	freopen("satellite.out","w",stdout);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	scanf("%d%d%*d%*d%d%d%d",&n,&m,&mo,&a,&b);
	for (int i=1;i<=n;++i)
		scanf("%d%d%d",&p[i].h,&p[i].x,&p[i].y);
	for (int i=1;i<=m;++i)
		scanf("%d%d",&q[i].x,&q[i].y),q[i].id=i;
	work_();
	for (int i=0;i<4;++i)
		work();
	for (int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}











