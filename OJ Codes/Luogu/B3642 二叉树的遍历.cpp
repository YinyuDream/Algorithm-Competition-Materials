#include<cstdio>
using namespace std;
const int maxn=100;
int a,b,n;
bool book[maxn];
struct node{
	int father,left,right;
}point[maxn];
struct fction{
	void dfs1(int x)
	{
		printf("%d ",x);
		if(point[x].left)dfs1(point[x].left);
		if(point[x].right)dfs1(point[x].right);
	}
	void dfs2(int x)
	{
		if(point[x].left)dfs2(point[x].left);
		printf("%d ",x);
		if(point[x].right)dfs2(point[x].right);
	}
	void dfs3(int x)
	{
		if(point[x].left)dfs3(point[x].left);
		if(point[x].right)dfs3(point[x].right);
		printf("%d ",x);
	}	
};
fction m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		point[a].father=b;
		if(!point[b].left)point[b].left=a;
		else point[b].right=a;
	}
	for(int i=1;i<=n;i++)
		if(!point[i].father)
		{
			m.dfs1(i);
			printf("\n");
			m.dfs2(i);
			printf("\n");
			m.dfs3(i);
			return 0;
		}
	return 0;
}
