#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
int a[maxn];
struct node{
	int lson,rson,sum;
}tree[maxn*30];
int root[maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return x;
}
void update(int &id,int l,int r,int pos,int val)
{
	if(!id)id=++k;
	if(l==r){
		tree[id].sum+=val;
		return ;
	}
	int mid=(l+r)/2;
	if(pos<=mid)update(tree[id].lson,l,mid,pos,val);
	else update(tree[id].rson,mid+1,r,pos,val);
	tree[id].sum=tree[tree[id].lson].sum+tree[tree[id].rson].sum;
}
int query(int id,int l,int r,int _l,int _r)
{
	if(!id)return 0;
	if(l==_l&r==_r)return tree[id].sum;
	int mid=(l+r)/2;
	if(_r<=mid)return query(tree[id].lson,l,mid,_l,_r);
	else if(_l>mid)return query(tree[id].rson,mid+1,r,_l,_r);
	else return query(tree[id].lson,l,mid,_l,mid)+query(tree[id].rson,mid+1,r,mid+1,_r);
}
int main(){
	//freopen("flower.in","r",stdin);
	//freopen("flower.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=0;i<=n;i++)
		root[i]=++k;
	for(int i=1;i<=n;i++)
		update(root[a[i]],1,n,i,1);
	for(int i=1,opt,l,r,c;i<=m;i++){
		scanf("%d",&opt);
		if(opt==1){
			l=read(),r=read(),c=read();
			printf("%d\n",query(root[c],1,n,l,r));
		}else{
			c=read();
			update(root[a[c]],1,n,c,-1);
			update(root[a[c]],1,n,c+1,1);
			update(root[a[c+1]],1,n,c,1);
			update(root[a[c+1]],1,n,c+1,-1);
			swap(a[c],a[c+1]);
		}
	}
	return 0;
}
