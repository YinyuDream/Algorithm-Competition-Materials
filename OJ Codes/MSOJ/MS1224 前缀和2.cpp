#include<cstdio>
using namespace std;
int n,m,x,y;
int a;
long long sum[100010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        sum[i]=a+sum[i-1]; 
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%lld",sum[y]-sum[x-1]);
        printf("\n");
    }
    return 0;
}