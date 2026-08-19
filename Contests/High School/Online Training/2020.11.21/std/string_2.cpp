using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#define N 1200005
#define ll long long
#define INF 1000000000
int n,m;
char _s[N],*s[N],*po=_s;
struct query{int s,t,id;} q[N];
bool cmpq(query a,query b){return a.t<b.t;}
struct Node{
	Node *c[26],*fail;
	int len;
} d[N],*S,*T;
int cnt;
void insert(int ch){
	if (T->c[ch] && T->c[ch]->len==T->len+1){
		T=T->c[ch];
		return;
	}
	Node *nw=&d[++cnt],*p;
	nw->len=T->len+1;
	for (p=T;p && !p->c[ch];p=p->fail)
		p->c[ch]=nw;
	if (!p)
		nw->fail=S;
	else{
		Node *q=p->c[ch];
		if (q->len==p->len+1)
			nw->fail=q;
		else{
			Node *clone=&d[++cnt];
			memcpy(clone,q,sizeof(Node));
			clone->len=p->len+1;
			for (;p && p->c[ch]==q;p=p->fail)
				p->c[ch]=clone;
			nw->fail=q->fail=clone;
		}
	}
	T=nw;
}
Node *at[N];
struct EDGE{
	int to;
	EDGE *las;
} e[N];
int ne;
EDGE *last[N];
void link(int u,int v){
//	printf("%d %d\n",u,v);
	e[ne]={v,last[u]};
	last[u]=e+ne++;
}
int in[N],out[N],nowdfn;
int fa[N],dep[N],siz[N],hs[N],top[N];
struct cmp{bool operator()(int a,int b){return dep[a]<dep[b];}};
map<int,int,cmp> ma[N];
int mn[N];
void init1(int x){
	in[x]=++nowdfn;
	siz[x]=1;
	for (EDGE *ei=last[x];ei;ei=ei->las){
		fa[ei->to]=x;
		dep[ei->to]=dep[x]+1;
		init1(ei->to);
		siz[x]+=siz[ei->to];
		if (siz[ei->to]>siz[hs[x]])
			hs[x]=ei->to;
	}
	out[x]=nowdfn;
}
void init2(int x,int t){
	top[x]=t;
	if (hs[x]){
		init2(hs[x],t);
		for (EDGE *ei=last[x];ei;ei=ei->las)
			if (ei->to!=hs[x])	
				init2(ei->to,ei->to);
	}
}
void mark(char s[]){
	Node *t=S;
	int L=0;
	for (char *ch=s;*ch;++ch){
		++L;
		t=t->c[*ch-'a'];
		ma[top[t-d]][t-d]=L;
		mn[top[t-d]]=min(mn[top[t-d]],dep[t-d]);
	}
}
void unmark(char s[]){
	Node *t=S;
	int L=0;
	for (char *ch=s;*ch;++ch){
		++L;
		t=t->c[*ch-'a'];
		ma[top[t-d]].erase(ma[top[t-d]].find(t-d));
		mn[top[t-d]]=INF;
	}
}
int query(int x){
	for (;x;x=fa[top[x]])
		if (mn[top[x]]<=dep[x]){
			map<int,int,cmp>::iterator p=ma[top[x]].upper_bound(x);
			--p;
			return p->second;
		}
	return 0;
}
int ans[N];
int main(){
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		s[i]=po;
		scanf("%s",s[i]);
		po=s[i]+(int)strlen(s[i])+1;
	}
	S=&d[cnt=1];
	for (int i=1;i<=n;++i){
		T=S;
		for (char *ch=s[i];*ch;++ch)
			insert(*ch-'a');
		at[i]=T;
	}
	for (int i=2;i<=cnt;++i)
		link(d[i].fail-d,i);
	init1(1);
	init2(1,1);
	for (int i=1;i<=cnt;++i)
		mn[i]=INF;
	for (int i=1;i<=m;++i)
		scanf("%d%d",&q[i].s,&q[i].t),q[i].id=i;
	sort(q+1,q+m+1,cmpq);
	for (int i=1,j=1;i<=n;++i){
		mark(s[i]);
		for (;j<=m && q[j].t==i;++j)
			ans[q[j].id]=query(at[q[j].s]-d);
		unmark(s[i]);
	}
	for (int i=1;i<=m;++i)
		printf("%d\n",ans[i]);
	return 0;
}