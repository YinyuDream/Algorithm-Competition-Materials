//#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10,inf=0x7f7f7f7f;
int n,m,top;
long long ans;
int a[maxn],b[maxn],sum[maxn];
struct node{
	int l,r,id;
}tree[maxn*4];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,ch=getchar();
	return x;
}
void lsh()
{
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	memset(b,0,sizeof b);
}
void update(int x)
{
	for(int i=x;i<=n;i+=i&(-i))
		b[i]++;
}
int query(int x)
{
	int cnt=0;
	for(int i=x;i>=1;i-=i&(-i))
		cnt+=b[i];
	return cnt;
}
void pushup(int id)
{
	if(a[tree[id*2].id]<a[tree[id*2+1].id])tree[id].id=tree[id*2].id;
	else tree[id].id=tree[id*2+1].id;
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r;
	if(tree[id].l==tree[id].r){
		tree[id].id=l;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	pushup(id);
}
void update(int id,int p)
{
	if(tree[id].l==p&&tree[id].r==p){
		tree[id].id=0;
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	if(p<=mid)update(id*2,p);
	else update(id*2+1,p);
	pushup(id);
}
int query(int id,int l,int r)
{
	if(tree[id].l==l&&tree[id].r==r)
	return tree[id].id;
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)return query(id*2,l,r);
	else if(l>mid)return query(id*2+1,l,r);
	else{
		int t1=query(id*2,l,mid),t2=query(id*2+1,mid+1,r);
		if(a[t1]<a[t2])return t1;
		else return t2;
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	a[0]=inf;
	lsh();
	for(int i=n;i>=1;i--)
	sum[i]=query(a[i]),
	update(a[i]),
	ans+=sum[i];
	printf("%lld\n",ans);
	build(1,1,n);
	for(int i=1,p;i<=m;i++)
	{
		p=read();
		int tmp=a[p],pt=p,top=a[pt];
		while(top<=tmp)
		{
			if(top==inf)break;
			ans-=sum[pt];
			a[pt]=inf;
			update(1,pt);
			pt=query(1,1,n);
			top=a[pt];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
