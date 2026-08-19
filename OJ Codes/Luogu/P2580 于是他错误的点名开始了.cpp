#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
struct node{
	int next[26];
	bool flag;
	int ask;
}tree[maxn];
void build(char *s)
{
	int l=strlen(s),id=0;
	for(int i=0;i<l;i++)
	{
		int t=s[i]-'a';
		if(tree[id].next[t]==0){
			tree[id].next[t]=++k;
		}
		id=tree[id].next[t];
	}
	tree[id].flag=1;
}
int find(char *s)
{
	int l=strlen(s),id=0;
	for(int i=0;i<l;i++)
	{
		int t=s[i]-'a';
		if(tree[id].next[t]==0){
			return 0;
		}
		id=tree[id].next[t];
	}
	if(tree[id].flag==0)return 0;
	tree[id].ask++;
	if(tree[id].ask==1)return 1;
	else return 2;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char a[55];
		scanf("\n%s",a);
		build(a);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		char a[55];
		scanf("\n%s",a);
		int p=find(a);
		if(p==0)printf("WRONG\n");
		else if(p==1)printf("OK\n");
		else printf("REPEAT\n");
	}	
	return 0;
}
