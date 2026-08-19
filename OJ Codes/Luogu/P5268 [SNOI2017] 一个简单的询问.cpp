#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,q,l,r,block,sum;
int a[maxn],bookl[maxn],bookr[maxn],ans[maxn];
struct node{
	int l,r,id,k;
}query[maxn];
bool cmp(node a,node b)
{
	if(a.l/block==b.l/block)return a.r<b.r;
	else return a.l/block<b.l/block;
}
void add(int pos,int opt)
{
	if(opt==1){
		sum+=bookr[a[pos]];
		bookl[a[pos]]++;
	}else{
		sum+=bookl[a[pos]];
		bookr[a[pos]]++;
	}
}
void del(int pos,int opt)
{
	if(opt==1){
		sum-=bookr[a[pos]];
		bookl[a[pos]]--;
	}else{
		sum-=bookl[a[pos]];
		bookr[a[pos]]--;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	block=sqrt(n);
	scanf("%d",&q);
	for(int i=1,l1,r1,l2,r2;i<=q;i++){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		query[i*4-3]={l1-1,l2-1,i,1};
		if(query[i*4-3].l>query[i*4-3].r)
		swap(query[i*4-3].l,query[i*4-3].r);
		query[i*4-2]={l1-1,r2,i,-1};
		if(query[i*4-2].l>query[i*4-2].r)
		swap(query[i*4-2].l,query[i*4-2].r);
		query[i*4-1]={l2-1,r1,i,-1};
		if(query[i*4-1].l>query[i*4-1].r)
		swap(query[i*4-1].l,query[i*4-1].r);
		query[i*4]={r1,r2,i,1};
		if(query[i*4].l>query[i*4].r)
		swap(query[i*4].l,query[i*4].r);
	}
	sort(query+1,query+4*q+1,cmp);
	for(int i=1;i<=q*4;i++){
		while(l<query[i].l)add(++l,1);
		while(l>query[i].l)del(l--,1);
		while(r>query[i].r)del(r--,2);
		while(r<query[i].r)add(++r,2);
		//printf("l:%d r:%d suml:%d sumr:%d sum:%d\n",query[i].l,query[i].r,bookl[1],bookr[1],sum);
		ans[query[i].id]+=query[i].k*sum;
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}