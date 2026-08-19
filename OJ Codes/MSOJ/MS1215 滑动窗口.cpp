#include<cstdio>
using namespace std;
 
const int maxn=1e6+10;
int n,k,x;
int l1=1,l2=1,r1=0,r2,k1=0,k2=0;
int ansmin[maxn],maxx[maxn];
 
struct node
{
    int s,id;
};
node a[maxn],b[maxn];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        while(l1<=r1&&a[r1].s<=x)r1--;
		a[++r1].s=x;
        a[r1].id=i;
        if(k1==a[l1].id&&i>k)l1++;   
        if(i>=k)k1++;
        maxx[i]=a[l1].s;
        //printf("%d ",l1);
        while(l2<=r2&&b[r2].s>=x)r2--;    
        b[++r2].s=x;
        b[r2].id=i;
        if(k2==b[l2].id&&i>k)l2++;
        if(i>=k)k2++;
        ansmin[i]=b[l2].s;
    }
    //for(int i=1;i<=n;i++)printf("%d",a[i].s);
    for(int i=k;i<=n;i++)printf("%d ",ansmin[i]);
    printf("\n");
    for(int i=k;i<=n;i++)printf("%d ",maxx[i]);
    printf("\n");
    return 0;
}