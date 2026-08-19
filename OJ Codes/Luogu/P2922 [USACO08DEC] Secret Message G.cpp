#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
int a[maxn];
struct node{
	int flag,sum;
	int son[2];
}trie[maxn];
void build(int l,int id,int len)
{
	if(l==len){
		trie[id].sum++;
		trie[id].flag++;
		return ;
	}
	if(trie[id].son[a[l+1]]==0)
	trie[id].son[a[l+1]]=++k;
	build(l+1,trie[id].son[a[l+1]],len);
	trie[id].sum=0;
	if(trie[id].son[0])trie[id].sum+=trie[trie[id].son[0]].sum;
	if(trie[id].son[1])trie[id].sum+=trie[trie[id].son[1]].sum;
	trie[id].sum+=trie[id].flag;
}
int query(int l)
{
	int cnt=0,id=0;
	for(int i=1;i<=l;i++)
	{
		if(trie[id].son[a[i]]==0)return cnt;
		id=trie[id].son[a[i]];
		cnt+=trie[id].flag;
	}
	cnt+=trie[id].sum-trie[id].flag;
	return cnt;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		int len=0;
		scanf("%d",&len);
		for(int j=1;j<=len;j++)
		scanf("%d",&a[j]);
		build(0,0,len);
	}
	for(int i=1;i<=n;i++)
	{
		int len=0;
		scanf("%d",&len);
		for(int j=1;j<=len;j++)
		scanf("%d",&a[j]);
		printf("%d\n",query(len));
	}
	return 0;
}
