#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,l=1,r,tot,block,a[maxn],sum[maxn],ans[maxn];
struct query{
	int l,r,id;
}q[maxn];
bool cmp(query a,query b)
{
	if(a.l/block==b.l/block)
	return a.r<b.r;
	return a.l<b.l;
}
void add(int x)
{
	if(a[x]>n)return ;
	if(sum[a[x]]==a[x])tot--;
	sum[a[x]]++;
	if(sum[a[x]]==a[x])tot++;
}
void del(int x)
{
	if(a[x]>n)return ;
	if(sum[a[x]]==a[x])tot--;
	sum[a[x]]--;
	if(sum[a[x]]==a[x])tot++;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	block=sqrt(n);
	for(int i=1;i<=m;i++)
	scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		while(l>q[i].l)add(--l);
		while(r<q[i].r)add(++r);
		while(l<q[i].l)del(l++);
		while(r>q[i].r)del(r--);
		ans[q[i].id]=tot;
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}