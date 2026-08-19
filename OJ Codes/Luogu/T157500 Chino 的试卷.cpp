#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,a[maxn];
namespace subtask1{
	int l=1,r,tot,block,sum[maxn],ans[maxn];
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
		if(sum[a[x]]==a[x])tot--;
		sum[a[x]]++;
		if(sum[a[x]]==a[x])tot++;
	}
	void del(int x)
	{
		if(sum[a[x]]==a[x])tot--;
		sum[a[x]]--;
		if(sum[a[x]]==a[x])tot++;
	}
	void work()
	{
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
	}
}
namespace subtask2{
	void work()
	{
		for(int i=1,l,r;i<=m;i++){
			scanf("%d%d",&l,&r);
			printf("%d\n",r-l+1==a[1]?1:0);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n<=100000)subtask1::work();
	else subtask2::work();
	return 0;
}