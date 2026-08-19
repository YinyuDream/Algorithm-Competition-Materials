//#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
long long n,l,r,ans,m;
long long a[maxn];
long long check(long long x)//假设中位数为x 
{

    long long cnt=0,_r=1;
    for(int i=1;i<=n;i++)
    {
        while(a[_r+1]-a[i]<=x&&_r<n)_r++;
        //_r=upper_bound(a+i,a+n+1,a[i]+x)-a-1;
        cnt+=_r-i;
    }
    return cnt;
}
int main(){
    //freopen("middle.in","r",stdin);
    //freopen("middle.out","w",stdout);
    while(scanf("%lld",&n)!=EOF)
    {
        m=n*(n-1)/2;
        if(m%2==0)m/=2;
        else m=(m+1)/2;
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        l=0,r=a[n]-a[1];
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid)>=m)r=mid-1;
            else l=mid+1;
        }
        printf("%lld\n",l);
    }
    return 0;
}
