#include<cstdio>
using namespace std;
const int maxn=4e5+10;
int n;
int a[maxn],sum[maxn],l[maxn],r[maxn];
struct node{
	int son[2];
	int flag;
}tree[maxn];
void build(int x)
{
	int id=0;
	for(int i=30;i>0;i--)
	{
		int t=(x>>i)&1;
		if(tree[id].son[t]==0)tree[id].son[t]=++k;
		id=tree[id].son[t];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i],build(sum[i]);
	
	return 0;
}
