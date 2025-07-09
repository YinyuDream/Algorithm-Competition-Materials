#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<pii> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].second;
    }
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    sort(a.begin(),a.end(),[](pii a,pii b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
    });
    int l=1,r=a[0].first;
    for(int i=0;i<n;i++)
        if(a[i].second==1){
            a[i].first+=k;
            break;
        }
    sort(a.begin(),a.end(),[](pii a,pii b){
       return a.first>b.first;
    });
    ll ans=1ll*a[0].first+a[n/2+(n%2==1)].first;
    auto check=[&](int x){
        for(int i=0;i<n;i++)
            a[i]=b[i];
        sort(a.begin(),a.end(),[&](pii a,pii b){
            if(a.first==b.first){
                return a.second>b.second;
            }
            return a.first>b.first;
        });
        int cnt=0,_k=k;
        for(int i=1;i<n;i++){
            if(a[i].first>=x)
                cnt++;
            else if(a[i].second==1){
                _k-=x-a[i].first;
                a[i].first=x;
                cnt++;
            }
            if(cnt>=(n+1)/2||_k<0){
                break;
            }
        }
        return _k>=0&&cnt>=(n+1)/2;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    check(r);
    sort(a.begin(),a.end(),[](pii a,pii b){
        return a.first>b.first;
    });
    ans=max(ans,(ll)a[0].first+a[n/2+(n%2==1)].first);
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}