#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt+=a[i]<0;
            a[i]=abs(a[i]);
        }
        sort(a+1,a+n+1);
        ll ans=0;
        for(int i=1;i<=n;i++)
            ans+=a[i];
        if(cnt%2==1)
            ans-=2*a[1];
        cout<<ans<<endl;
    }
    return 0;
}