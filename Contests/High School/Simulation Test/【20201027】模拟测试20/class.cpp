#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3e5+10;
int n,m;
int p[maxn],minx[maxn],maxx[maxn],num[maxn];
int opt[maxn],l[maxn],r[maxn],t[maxn],a[maxn],delta[maxn],is_big[maxn],book[maxn];
struct node{
	int sum[26],mx[26],num[26];
}tree[maxn*4];
void lsh()
{
	static int help[maxn];
	for(int i=1;i<=n;i++)
		help[i]=p[i];
	for(int i=1;i<=m;i++){
		help[n+i]=l[i];
		help[n+m+i]=r[i];
	}
	sort(help+1,help+n+m*2+1);
	int cnt=unique(help+1,help+n+m*2+1)-help-1;
	for(int i=1;i<=n;i++)
		p[i]=lower_bound(help+1,help+cnt+1,p[i])-help;
	for(int i=1;i<=m;i++){
		l[i]=lower_bound(help+1,help+cnt+1,l[i])-help;
		r[i]=lower_bound(help+1,help+cnt+1,r[i])-help;
	}
}
void pushup(int id)
{
	for(int i=0;i<=25;i++){
		tree[id].mx[i]=max(tree[id*2].mx[i],tree[id*2+1].mx[i]);
		tree[id].sum[i]=tree[id*2].sum[i]+tree[id*2+1].sum[i];
		tree[id].num[i]=tree[id*2].num[i]+tree[id*2+1].num[i];
	}
}
void build(int id,int l,int r)
{
	if(l==r){
		if(book[l]){
			tree[id].mx[is_big[l]*13+delta[l]]=a[l];
			tree[id].sum[is_big[l]*13+delta[l]]=a[l];
			tree[id].num[is_big[l]*13+delta[l]]=1;
		}
		return ;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	pushup(id);
}
node query(int id,int l,int r,int _l,int _r)
{
	if(l==_l&&r==_r)return tree[id];
	int mid=(l+r)/2;
	if(_r<=mid)return query(id*2,l,mid,_l,_r);
	else if(_l>mid)return query(id*2+1,mid+1,r,_l,_r);
	else{
		node t1=query(id*2,l,mid,_l,mid),t2=query(id*2+1,mid+1,r,mid+1,_r),t3;
		for(int i=0;i<=25;i++){
			t3.mx[i]=max(t1.mx[i],t2.mx[i]);
			t3.sum[i]=t1.sum[i]+t2.sum[i];
			t3.num[i]=t1.num[i]+t2.num[i];
		}
		return t3;
	}
}
int work(int _opt,int _l,int _r,int _t)
{
	node t=query(1,1,n+m*2,_l,_r);
	int sum=0;
	for(int i=0;i<=25;i++)
		sum+=t.num[i];
	if(!sum)return -1;
	if(_opt==0){
		sum=0;
		for(int i=1;i<=12;i++)
			sum+=t.sum[i]+t.num[i]*abs((_t+i)%(2*i)-i);
		for(int i=1;i<=12;i++)
			sum+=t.sum[i+13]-t.num[i+13]*abs((_t+i)%(2*i)-i);
		sum+=t.sum[0];
		sum+=t.sum[13];
		return sum;
	}else{
		int mx=0;
		for(int i=1;i<=12;i++)
			mx=max(mx,t.mx[i]+abs((_t+i)%(2*i)-i));
		for(int i=1;i<=13;i++)
			mx=max(mx,t.mx[i+13]-abs((_t+i)%(2*i)-i));
		mx=max(mx,t.mx[0]);
		mx=max(mx,t.mx[13]);
		return mx;
	}
}
int main(){
	freopen("class.in","r",stdin);
	freopen("class.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&p[i],&minx[i],&maxx[i],&num[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&opt[i],&t[i],&l[i],&r[i]);
	lsh();	
	for(int i=1;i<=n;i++){
		book[p[i]]=1;
		a[p[i]]=num[i]?maxx[i]:minx[i];
		delta[p[i]]=maxx[i]-minx[i];
		is_big[p[i]]=num[i];
	}
	build(1,1,n+m*2);
	for(int i=1;i<=m;i++)
		printf("%d\n",work(opt[i],l[i],r[i],t[i]));
	return 0;
}
