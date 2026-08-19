#include<cstdio>
#include<cstring>
using namespace std;
char a[100],b[100]; 
void dfs(int l,int r,int k)
{
	int m;
	for(int i=l;i<=r;i++)
	{
		if(a[k]==b[i])
		{
			m=i;break;
		}
	}
	printf("%c",b[m]);
	if(m-1>=l)dfs(l,m-1,k-(r-m+1));
	if(m+1<=r)dfs(m+1,r,k-1);
}
int main(){
	scanf("%s %s",b,a);
	dfs(0,strlen(a)-1,strlen(a)-1);
	return 0;
}
