#include<cstdio>
using namespace std;
  
const int maxn=1e6+10;
int n,k,x;
int l1=1,r1=0,k1=0;
int maxx[maxn];
  
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
    }
    for(int i=k;i<=n;i++)printf("%d\n",maxx[i]);
    return 0;
}