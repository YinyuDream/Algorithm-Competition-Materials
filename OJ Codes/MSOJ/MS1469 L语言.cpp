#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
char a[maxn];
struct node{
	int son[26];
	bool flag;
}tree[maxn];
int book[maxn];
void build()
{
	int l=strlen(a),id=0;
	for(int i=0;i<l;i++){
		int t=a[i]-'a';
		if(tree[id].son[t]==0){
			tree[id].son[t]=++k;
		}
		id=tree[id].son[t];
	}
	tree[id].flag=1;
}
int ask()
{
	memset(book,0,sizeof book);
	int ans=0;
	int l=strlen(a),id=0;
	for(int i=0;i<l;i++){
		int t=a[i]-'a';
		id=tree[id].son[t];
		if(id==0)break;
		if(tree[id].flag==1)book[i]=1;
	}
	for(int i=0;i<l;i++){
		if(book[i]==0)continue;
		else ans=i;
		id=0;
		for(int j=i+1;j<l;j++){
			int t=a[j]-'a';
			id=tree[id].son[t];
			if(id==0)break;
			if(tree[id].flag==1)book[j]=1;
		}
	}
	return ans>0?ans+1:0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("\n%s",a);
		build();
	}
	for(int i=1;i<=m;i++){
		scanf("\n%s",a);
		printf("%d\n",ask());
	}
	return 0;
	
}