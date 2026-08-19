#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+10;
int n,m;
int cnt[maxn];
struct trie{
	bool flag;
	int son[26];
}tree[maxn][5*maxn];
void update(char *s,int k)
{
	int len=strlen(s),id=0;
	for(int i=0;i<len;i++){
		if(tree[k][id].son[s[i]-'a']==0)
		tree[k][id].son[s[i]-'a']=++cnt[k];
		id=tree[k][id].son[s[i]-'a'];
	}
	tree[k][id].flag=1;
}
bool query(char *s,int k)
{
	int len=strlen(s),id=0;
	for(int i=0;i<len;i++){
		if(tree[k][id].son[s[i]-'a']==0)return false;
		id=tree[k][id].son[s[i]-'a'];
	}
	return tree[k][id].flag;
}
int main(){
	scanf("%d",&n);
	for(int i=1,p;i<=n;i++)
	{
		char s[30];
		scanf("%d",&p);
		for(int j=1;j<=p;j++)
			scanf("%s",s),update(s,i);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		char s[30];
		scanf("%s",s);
		for(int j=1;j<=n;j++)
			if(query(s,j))
				printf("%d ",j);
		puts("");
	}
	return 0;
}
