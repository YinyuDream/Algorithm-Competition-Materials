#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e3+10;
const ll p=998244353;
int T,n;
int a[maxn];
ll pw2[maxn],f[maxn][maxn];
void pre()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=a[n];j++)
            f[i][j]=0;
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=5000;j++){
            f[i][j]=f[i-1][j];
            if(j-a[i]>=0)
                f[i][j]+=f[i-1][j-a[i]];
            f[i][j]%=p;
        }
    }
}
ll work(int pos)
{
    ll sum=0,num=0;
    for(int i=a[pos];i<=5000;i++){
        if((i+a[pos])%2==0)num+=(i+a[pos])*f[pos-1][i]/2;
        else num+=((i+a[pos])/2+1)*f[pos-1][i];
        sum+=f[pos-1][i];
        sum%=p;
        num%=p;
    }
    num=(num+((pw2[pos-1]-sum)%p*a[pos]))%p;
    return num;
}
int main(){
    pw2[0]=1;
    for(int i=1;i<maxn;i++)
        pw2[i]=pw2[i-1]*2%p;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=a[1];
    pre();
    for(int i=2;i<=n;i++)
        ans=(ans+work(i))%p;
    cout<<(ans+p)%p<<endl;
    return 0;
}