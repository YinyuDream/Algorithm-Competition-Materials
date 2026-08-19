#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;//区间长度 
struct node{
	int lef,rig;
	int sum;
	int lazy;
} tree[maxn*4];
int a[maxn];//原数组 
int n;
inline int read(){
	int x=0,f=1;
	char ch; ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void build(int id,int L,int R){//建一棵区间为L~R的线段树 
	tree[id].lef=L; tree[id].rig=R; tree[id].sum=tree[id].lazy=0;
	if(L==R){ tree[id].sum=a[L]; return;}//叶子节点(一个点)
	int mid=(L+R)/2;
	build(id*2,L,mid);build(id*2+1,mid+1,R);//递归建左右子树 
	//回溯时利用左右子树修改区间L~R的sum值
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
}
inline void down(int id){//标记下传函数 
	tree[id*2].lazy+=tree[id].lazy;//标记下传到左子树 
	tree[id*2].sum+=(tree[id*2].rig-tree[id*2].lef+1)*tree[id].lazy;
	tree[id*2+1].lazy+=tree[id].lazy;//标记下传到右子树 
	tree[id*2+1].sum+=(tree[id*2+1].rig-tree[id*2+1].lef+1)*tree[id].lazy;
	tree[id].lazy=0;//清空标记 
}
inline  void update(int id,int L,int R,int val){
	if(tree[id].lef>R || tree[id].rig<L) return;//处理区间与线段树区间无任何重合 
	if(L<=tree[id].lef && tree[id].rig<=R)//线段树id点的区间整体被覆盖 
	{
		tree[id].lazy+=val;
		tree[id].sum+=(tree[id].rig-tree[id].lef+1)*val;
		return;
	} 
	if(tree[id].lazy>0) down(id);//递归左右子树之前，下传标记,反正要递归下去，节省时间
	update(id*2,L,R,val);update(id*2+1,L,R,val);//递归左右子树更新
	//回溯时利用左右子树修改区间L~R的sum值
	tree[id].sum=tree[id*2].sum+tree[id*2+1].sum; 
}
inline int query(int id,int L,int R){//查询函数 
	if(tree[id].lef>R || tree[id].rig<L) return 0;
	if(L<=tree[id].lef && tree[id].rig<=R) return tree[id].sum;
	if(tree[id].lazy>0) down(id);
	return query(id*2,L,R)+query(id*2+1,L,R);
} 
int main()
{
	int opt,x,y,val,n,m;
	n=read();m=read();
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n); 
	for(int i=1;i<=m;i++){
		opt=read();
		if(opt==1){
			x=read();y=read();val=read();
			update(1,x,y,val);
		} else if(opt==2){
			x=read();y=read();
			printf("%d\n",query(1,x,y));
		}
	}
	return 0;
}
 
