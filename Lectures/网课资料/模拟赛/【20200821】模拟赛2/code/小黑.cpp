#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n,m,q;
int a[maxn][maxn],b[maxn],l[maxn];
int find(int x,int p)
{
	if(x==0)return 0;
	for(int i=1;i<=n;i++)
		if(a[p][i]==x)
			return i; 
}
int query(int x)
{
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int book=0;
		for(int j=1;j<=l[i]-x+1;j++)
		{
			book=0;
			for(int k=j;k<=j+x-1;k++)
			{
				if(a[i][k]!=b[(k-j)+1]){
					book=1;
					break;
				}
			}
			if(book==0){
				cnt++;
				break;
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[0][i]);
	l[0]=n;
	for(int i=1;i<=m;i++)
	{
		int opt,x,y;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d",&x);
			int pos=find(x,i-1);
			for(int j=1;j<pos;j++)
			a[i][j]=a[i-1][j];
			for(int j=pos+1;j<=n;j++)
			a[i][j-1]=a[i-1][j];
			l[i]=l[i-1]-1;
		}
		else
		{
			scanf("%d%d",&x,&y);
			int pos=find(x,i-1);
			for(int j=1;j<=pos;j++)
			a[i][j]=a[i-1][j];
			a[i][pos+1]=y;
			for(int j=pos+2;j<=n;j++)
			a[i][j]=a[i-1][j-1];
			l[i]=l[i-1]+1;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d",&b[j]);
		printf("%d\n",query(k));
	}
}
