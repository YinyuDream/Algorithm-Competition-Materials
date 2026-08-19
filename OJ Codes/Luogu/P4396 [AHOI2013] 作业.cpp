#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,l=1,r,block;
int a[maxn],ans[maxn],sum[maxn];
int book[maxn],cnt[maxn],ans2[maxn];
struct query{
	int l,r,a,b,id;
}q[maxn];
bool cmp(query a,query b)
{
	if(a.l/block==b.l/block)
	return a.r<b.r;
	else 
	return a.l/block<b.l/block;
}
int lowbit(int x)
{
	return x&(-x);
}
void add(int num,int opt)
{
	int pos=a[num];
	for(int i=pos;i<=n;i+=lowbit(i))
	sum[i]+=opt;
}
int query(int pos)
{
	int t=0;
	for(int i=pos;i;i-=lowbit(i))
	t+=sum[i];
	return t;
}
int find(int l,int r)
{
	return query(r)-query(l-1);
}
void change(int pos,int opt)
{
	for(int i=pos;i<=n;i+=lowbit(i))
	cnt[i]+=opt;
}
void add2(int num,int opt)
{
	if(opt==1){
		book[num]++;
		if(book[num]==1)
		change(num,1);
	}else{
		book[num]--;
		if(book[num]==0)
		change(num,-1);
	}
}
int query2(int pos)
{
	int t=0;
	for(int i=pos;i;i-=lowbit(i))
	t+=cnt[i];
	return t;
}
int find2(int l,int r)
{
	return query2(r)-query2(l-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	scanf("%d%d%d%d",&q[i].l,&q[i].r,&q[i].a,&q[i].b),q[i].id=i;
	block=sqrt(n);
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l)add(l++,-1),add2(a[l-1],-1);
		while(l>q[i].l)add(--l,1),add2(a[l],1);
		while(r<q[i].r)add(++r,1),add2(a[r],1);
		while(r>q[i].r)add(r--,-1),add2(a[r+1],-1);
		ans[q[i].id]=find(q[i].a,q[i].b);
		ans2[q[i].id]=find2(q[i].a,q[i].b);
	}
	for(int i=1;i<=m;i++)
	printf("%d %d\n",ans[i],ans2[i]);
	return 0;
}
