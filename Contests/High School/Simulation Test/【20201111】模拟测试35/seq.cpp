#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int T,n,k;
struct node{
	int l,r,key,val,size;
}tree[maxn*30];
int root[maxn];
int add(int x)
{
	int now=++k;
	tree[now].key=rand();
	tree[now].val=x;
	tree[now].size=1;
	return now;
}
void pushup(int u)
{
	tree[u].size=tree[tree[u].l].size+tree[tree[u].r].size+1;
}
int merge(int l,int r)
{
	if(!l||!r)return l+r;
	if(tree[l].key<=tree[r].key){
		int now=++k;
		tree[now]=tree[l];
		tree[now].r=merge(tree[now].r,r);
		pushup(now);
		return now;
	}else{
		int now=++k;
		tree[now]=tree[r];
		tree[now].l=merge(l,tree[now].l);
		pushup(now);
		return now;
	}
}
int kth(int u,int num)
{
	if(tree[tree[u].l].size>=num)return kth(tree[u].l,num);
	else if(tree[tree[u].l].size+1==num)return tree[u].val;
	else return kth(tree[u].r,num-tree[tree[u].l].size-1);
}
int main(){
	//freopen("seq.in","r",stdin);
	//freopen("seq.out","w",stdout);
	srand((unsigned)time(0));
	scanf("%d",&T);
	while(T--){
		k=0;
		memset(tree,0,sizeof tree);
		memset(root,0,sizeof root);
		scanf("%d",&n);
		for(int i=1,opt,cnt=0,x;i<=n;i++){
			scanf("%d%d",&opt,&x);
			if(opt==1){
				cnt++;
				root[cnt]=merge(root[cnt-1],add(x));
			}else if(opt==2){
				cnt++;
				root[cnt]=root[cnt-x-1];
			}else{
				printf("%d\n",kth(root[cnt],x));
			}
		}
	}
	return 0;
}
