#include<cstdio>
using namespace std;
int n,a,b;
int fa[100],dep[100];
void dfs(int x)
{
	if(!fa[x]){
	dep[x]=1;return;
	} 
	if(dep[x])return;
	dfs(fa[x]);
	dep[x]=dep[fa[x]]+1;
}
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<n;i++){
		int A,B;
		scanf("%d%d",&A,&B);
		fa[A]=B;
	}
	dfs(a),dfs(b);
	while(dep[a]!=dep[b]){
		if(dep[a]>dep[b])a=fa[a];
		else b=fa[b];
	}
	while(a!=b){
		a=fa[a];b=fa[b];
	}
	printf("%d",a);
	return 0;
}
