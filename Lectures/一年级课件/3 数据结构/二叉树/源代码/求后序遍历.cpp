#include<cstdio>
#include<cstring>
using namespace std;



char a[100],b[100];//a前序，b中序

void dfs(int l,int r,int k)//k表示当前子树的根节点在a中的下标。 
//在b数组的（l,r)位置找 当前子树的根节点。 
{
	int m;
	for(int i=l;i<=r;i++)
		if(a[k]==b[i])
		{
			m=i;
			break;
		}
	if(m-1>=l)dfs(l,m-1,k+1);
	if(r>=m+1)dfs(m+1,r,k+m-l+1);
	printf("%c",b[m]);
}
int main()
{
	scanf("%s %s",a,b);
	int len=strlen(a);
	dfs(0,len-1,0);
} 
