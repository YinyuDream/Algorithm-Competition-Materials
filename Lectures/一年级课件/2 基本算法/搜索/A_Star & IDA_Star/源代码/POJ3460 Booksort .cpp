#include<cstdio>
using namespace std;
int n;
int a[50],tmp[50];
inline bool cheak()
{
	for(int i=1;i<=n;i++)
		if(a[i]!=i)return false;
	return true;
}
inline void rev(int l,int r,int k)
{
	for(int i=l;i<=r;i++)tmp[i]=a[i];
	
}
void dfs(int cur,int deep,bool flag)
{
	if(cheak())return 1;
	if(cur>=deep)return 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=n+1;k++)
			{
				if(k>=i||k<=j)continue;
				rev(i,j,k);
				if(dfs(cur+1,deep)){
					rev(i,j,k);return 1;
				}
				rev(i,j,k);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int k=1;
	while(k<=4)
	{
		if(dfs(0,k))break;
		k++;
	}
	if(k>=5)printf("5 or more");
	else printf("%d",k);
	return 0;
}
