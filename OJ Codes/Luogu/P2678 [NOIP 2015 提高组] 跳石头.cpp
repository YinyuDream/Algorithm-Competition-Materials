#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,L;
int a[maxn];
 
bool cheak(int x)
{
    int cnt=0,tmp=0;
    for(int i=0;i<=n+2;i++)
    {
        if(a[i]-a[tmp]>=x)
        {
            cnt+=(i-tmp-1);
            tmp=i;
             
        }   
    }
    if(cnt<=m)return 1;
    else return 0;
}
int main()
{
    //freopen("house.in","r",stdin);
   // freopen("house.out","w",stdout);
    scanf("%d%d%d",&L,&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=L;
    sort(a+1,a+n+2);
    a[n+2]=1e9;
    int left=1,right=L;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(cheak(mid))left=mid+1;
        else right=mid-1;
    }
    printf("%d",right);
    return 0;
}