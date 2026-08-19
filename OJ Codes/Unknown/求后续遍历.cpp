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
	if(m-1>=l)dfs(l,m-1,k+1);
	if(m+1<=r)dfs(m+1,r,m+1+k-l);
	printf("%c",b[m]);
}
int main(){ 
	scanf("%s %s",a,b);
	dfs(0,strlen(a)-1,0);
	return 0;
}
