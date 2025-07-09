#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,lim;
int a[maxn];
ll sum[maxn],f[maxn][11];
int mn(int l,int r)
{
    int res=1e9;
    for(int i=l;i<=r;i++)
        res=min(res,a[i]);
    return res;

}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>lim;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            f[i][0]=sum[i];
            for(int j=1;j<=10;j++)
                f[i][j]=1e18;
        }
        for(int i=1;i<=lim;i++)
            f[1][i]=a[1];
        for(int i=2;i<=n;i++){
            for(int j=1;j<=lim;j++){
                f[i][j]=f[i-1][j]+a[i];
                for(int k=1;k<=j;k++){
                    int low=i-(k+1);
                    if(low>=0)
                        f[i][j]=min(f[i][j],f[low][j-k]+1ll*mn(low+1,i)*(k+1));
                }
            }
        }
        cout<<f[n][lim]<<endl;
    }
    return 0;
}