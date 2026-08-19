#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,c,x,y,cnt;
int a[maxn];
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	x=1;y=n;
	while(x<y)
	{
		if(a[x]+a[y]<=c)
		{
			x++;y--;cnt++;
		}
		else if(a[y]<=c)
		{
			y--;cnt++;
		}
		else
		{
			printf("no way\n");
			return 0;
		}
	}
	if(x==y)cnt++;
	printf("%d",cnt);
	return 0;
}