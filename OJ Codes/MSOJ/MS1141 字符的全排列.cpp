#include<cstdio>
#include<cstring> 
using namespace std;
char a[10];
bool b[130];
char c[10];
int len;
void dfs(int k)
{
	if(k==len+1)
	{
		printf("%s\n",c);return;
	}
	for(int i=0;i<len;i++)
	{
		if(b[a[i]-'a']==0)
		{
			b[a[i]-'a']=1;
			c[k-1]=a[i];
			dfs(k+1);
			b[a[i]-'a']=0;
		}
	}
	
}
int main()
{
	scanf("%s",a);
	len=strlen(a);
	dfs(1);
	return 0;
}