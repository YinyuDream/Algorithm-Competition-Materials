#include<cstdio>
using namespace std;
int a,b,n,ans,k;
int main()
{
	scanf("%d%d%d",&a,&b,&n);
	k=a%b;
	for(int i=1;i<=n;i++)
	{
		k=k*10;
		ans=k/b;
		k=k%b;
	}
printf("%d",ans);
return 0;
}
