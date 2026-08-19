#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,q,a[maxn];
struct segment_tree{
	int l,r,len,lmax,rmax,zmax,lcol,rcol,lazy;
}tree[maxn*4];
void pushup(int id)
{
	tree[id].zmax=max(tree[id*2].zmax,tree[id*2+1].zmax);
	if(tree[id*2].rcol!=tree[id*2+1].lcol)tree[id].zmax=max(tree[id].zmax,tree[id*2].rmax+tree[id*2+1].lmax); 
	tree[id].lmax=tree[id*2].lmax;
	if(tree[id*2].lmax==tree[id*2].len&&tree[id*2].rcol!=tree[id*2+1].lcol)tree[id].lmax=tree[id*2].len+tree[id*2+1].lmax;
	tree[id].rmax=tree[id*2+1].rmax;
	if(tree[id*2+1].rmax==tree[id*2+1].len&&tree[id*2].rcol!=tree[id*2+1].lcol)tree[id].rmax=tree[id*2+1].len+tree[id*2].rmax;
	tree[id].lcol=tree[id*2].lcol,tree[id].rcol=tree[id*2+1].rcol; 
}
void pushdown(int id)
{
	tree[id*2].lazy=tree[id*2+1].lazy=tree[id].lazy;
	tree[id*2].lmax=tree[id*2+1].lmax=1;
	tree[id*2].zmax=tree[id*2+1].zmax=1;
	tree[id*2].rmax=tree[id*2+1].rmax=1;
	tree[id*2].lcol=tree[id*2+1].lcol=tree[id].lazy;
	tree[id*2].rcol=tree[id*2+1].rcol=tree[id].lazy;
	tree[id].lazy=-1;
}
void build(int id,int l,int r)
{
	tree[id].l=l,tree[id].r=r,tree[id].len=r-l+1,tree[id].lazy=-1;
	if(tree[id].l==tree[id].r){
		tree[id].zmax=tree[id].lmax=tree[id].rmax=1;
		tree[id].lcol=tree[id].rcol=a[l];
		return ;
	}
	int mid=(tree[id].l+tree[id].r)/2;
	build(id*2,l,mid),build(id*2+1,mid+1,r);
	pushup(id);
}
void update(int id,int l,int r,int c)
{
	if(tree[id].l==l&&tree[id].r==r){
		tree[id].zmax=tree[id].lmax=tree[id].rmax=1;
		tree[id].lcol=tree[id].rcol=c;
		tree[id].lazy=c;
		return ;
	}
	if(tree[id].lazy!=-1)pushdown(id);
	int mid=(tree[id].l+tree[id].r)/2;
	if(r<=mid)update(id*2,l,r,c);
	else if(l>mid)update(id*2+1,l,r,c);
	else update(id*2,l,mid,c),update(id*2+1,mid+1,r,c);
	pushup(id);
}
int main(){
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		char ch=getchar();
		while(ch!='0'&&ch!='1')ch=getchar();
		a[i]=(ch=='1');
	}
	build(1,0,n-1);
	for(int i=1,st,len,ans,val;i<=q;i++){
		scanf("%d%d%d",&st,&len,&val);
		if(st+len-1<n)update(1,st,st+len-1,val);
		else update(1,st,n-1,val),update(1,0,st+len-n-1,val);
		ans=tree[1].zmax;
		if(tree[1].rcol!=tree[1].lcol)ans=max(ans,tree[1].rmax+tree[1].lmax);
		if(ans>=n)puts("-1");
		else printf("%d\n",(ans-1)/2);
	}
	return 0;
}
