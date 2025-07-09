#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
ll a[maxn];
ll L(ll x,ll y){
    return x/__gcd(x,y)*y;
}
void work(int x,int &ans){
    int cnt=0,lcm=1;
    for(int i=1;i<=n;i++)
        if(x==a[i])
            return;
    for(int i=1;i<=n;i++){
        if(x%a[i]==0){
            cnt++;
            lcm=L(lcm,a[i]);
        }
    }
    if(lcm!=x) return;
    ans=max(ans,cnt);
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        sort(a+1,a+n+1);
        ll lcm=a[1];
        bool flag=true;
        for(int i=2;i<=n;i++){
            lcm=L(lcm,a[i]);
            if(lcm>1e9){
                flag=false;
                break;
            }
        }
        if(flag==false||lcm!=a[n]){
            cout<<n<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=sqrt(a[n]);i++){
            if(a[n]%i==0){
                work(i,ans);
                work(a[n]/i,ans);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}