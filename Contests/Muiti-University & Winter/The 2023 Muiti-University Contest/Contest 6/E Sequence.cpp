#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,q;
ll a[maxn],sum[maxn],cnt[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+a[i];
        for(int i=1;i<=n;i++)
            cnt[i]=cnt[i-1]+(sum[i]&1);
        for(int i=1;i<=q;i++){
            int l,r,k;
            cin>>l>>r>>k;
            if((sum[r]-sum[l-1])%2!=0){
                cout<<"NO"<<endl;
                continue;
            }
            if(sum[l-1]&1){
                if(cnt[r-1]-cnt[l-1]>=k-1)
                    cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }else{
                if((r-l)-(cnt[r-1]-cnt[l-1])>=k-1)
                    cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}