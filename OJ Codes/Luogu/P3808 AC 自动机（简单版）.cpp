#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,k;
char a[maxn];
struct node{
	int son[26];
	int flag,fail;
}tree[maxn];
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
	tree[id].flag++;
}
queue<int>q;
void fail_point()
{
	int id=0;
	for(int i=0;i<26;i++){
		int j=tree[id].son[i];
		if(j!=0){
			tree[id].fail=id;
			q.push(j);
		}
	}
	while(q.size()){
		int now=q.front();q.pop();
		for(int i=0;i<26;i++){
			int j=tree[now].son[i];
			if(j==0){
				tree[now].son[i]=tree[tree[now].fail].son[i];
				continue;
			}
			tree[j].fail=tree[tree[now].fail].son[i];
			q.push(j);
		}
	}
}
int serach()
{
	int id=0,l=strlen(a),ans=0;
	for(int i=0;i<l;i++){
		int j=tree[id].son[a[i]-'a'];
		while(j&&tree[j].flag!=-1){
			ans+=tree[j].flag;
			tree[j].flag=-1;
			j=tree[j].fail;
		}
		id=tree[id].son[a[i]-'a'];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("\n%s",a);
		build();	
	}
	fail_point();
	scanf("\n%s",a);
	printf("%d",serach());
	return 0;
}
