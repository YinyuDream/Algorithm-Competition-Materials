#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
struct node{
	int son[10];
	bool flag;
}tree[maxn];
int k,t,n;
char a[maxn];
bool build()
{
	 
	int l=strlen(a),id=0;
	bool book=false,bok=true;
	for(int i=0;i<l;i++){
		int t=a[i]-'0';
		if(tree[id].son[t]==0)
			tree[id].son[t]=++k,bok=false;
		id=tree[id].son[t];
		if(tree[id].flag==1)book=true;
	}
	tree[id].flag=1;
	if((book==false&&bok==true)||book==true)return true;
	else return false;
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		memset(tree,0,sizeof tree),k=0;
		scanf("%d",&n);
		bool bk=0;
		for(int i=1;i<=n;i++){
			scanf("\n%s",a);
			if(build()==true)bk=1;	
		}
		printf("%s\n",bk==0?"YES":"NO");
	}
	return 0;
} 