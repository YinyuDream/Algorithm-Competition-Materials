#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,size,k1,k2,now,l,r,sum;
struct node{
	int l,r,id,t;
}q[maxn];
struct point{
	int id,color;
}c[maxn];
int book[maxn],ans[maxn],a[maxn];
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,
	ch=getchar();
	return x;
}
inline bool cmp(node a,node b)
{
	if(a.l/size==b.l/size){
		if(a.r/size==b.r/size)return a.t<b.t;
		else return a.r<b.r;
	}else{
		return a.l/size<b.l/size;
	}
}
inline void change(int x)
{
	if(c[x].id>=l&&c[x].id<=r)
	sum+=++book[c[x].color]==1,
	sum-=--book[a[c[x].id]]==0;
	swap(c[x].color,a[c[x].id]);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	for(int i=1;i<=m;i++)
	{
		char opt;
		scanf("\n%c",&opt);
		if(opt=='Q')
		{
			k1++;
			q[k1].l=read();
			q[k1].r=read();
			q[k1].id=k1;
			q[k1].t=k2;
		}
		else
		{
			k2++;
			c[k2].id=read();
			c[k2].color=read();
		}
	}
	size=ceil(exp((log(n)+log(m))/3));
	sort(q+1,q+k1+1,cmp);
	for(int i=1;i<=k1;i++)
	{
		while(l<q[i].l)sum-=!--book[a[l++]];
		while(l>q[i].l)sum+=!book[a[--l]]++;
		while(r<q[i].r)sum+=!book[a[++r]]++;
		while(r>q[i].r)sum-=!--book[a[r--]];
		while(now<q[i].t)change(++now);
		while(now>q[i].t)change(now--);
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=k1;i++)
	printf("%d\n",ans[i]);
	return 0;
}