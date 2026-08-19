#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e4+10;
int n,t;
int sum[maxn],ans[maxn];
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=2000;i++)
	{
		memset(sum,0,sizeof sum);
		for(int j=1;j<=i;j++)
			sum[j]=sum[j-1]+i/gcd(j,i);
		ans[i]=sum[i];
	}
	for(int i=1;i<=t;i++)
	{
		int q;
		scanf("%d",&q);
		printf("%d\n",ans[q]);
	}
	return 0;
}
