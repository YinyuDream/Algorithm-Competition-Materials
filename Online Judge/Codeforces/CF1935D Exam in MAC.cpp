#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
ll c,a[maxn],sum_o[maxn],sum_e[maxn];
ll ans;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>c;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum_o[i]=sum_o[i-1];
            sum_e[i]=sum_e[i-1];
            if(a[i]%2==0){
                sum_e[i]++;
            }
            if(a[i]%2==1){
                sum_o[i]++;
            }
        }
        ans=(c+2)*(c+1)/2;
        for(int i=1;i<=n;i++){
            ll num=a[i]/2+1;
            ans-=num;
        }
        for(int i=1;i<=n;i++){
            ll num=c-a[i]+1;
            ans-=num;
        }
        for(int i=1;i<=n;i++){
            if(a[i]%2==0){
                ans+=sum_e[n]-sum_e[i-1];
            }else{
                ans+=sum_o[n]-sum_o[i-1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}