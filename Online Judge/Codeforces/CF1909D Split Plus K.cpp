#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
ll k,a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        ll gcd=a[1]-k;
        for(int i=2;i<=n;i++)
            gcd=__gcd(gcd,a[i]-k);
        if(gcd==0){
            bool flag=true;
            for(int i=1;i<=n;i++){
                if(a[i]!=k){
                    flag=false;
                    cout<<-1<<endl;
                    break;
                }
            }
            if(flag)
                cout<<0<<endl;
            continue;
        }
        ll ans=0;
        bool flag=true;
        for(int i=1;i<=n;i++){
            ll t=(a[i]-k)/gcd-1;
            if(t<0){
                flag=false;
                break;
            }
            ans+=(a[i]-k)/gcd-1;
        }
        if(flag)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}