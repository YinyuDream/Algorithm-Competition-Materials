#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> pos(m+1);
    vector<ll> val(m+1),sum(m+1);
    vector<pair<int,ll>> a(m+1);
    for(int i=1;i<=m;i++){
        cin>>a[i].first;
    }
    for(int i=1;i<=m;i++){
        cin>>a[i].second;
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=m;i++){
        pos[i]=a[i].first;
        val[i]=a[i].second;
    }
    sum[m]=val[m];
    for(int i=m-1;i>=1;i--){
        sum[i]=sum[i+1]+val[i];
    }
    for(int i=1;i<=m;i++){
        if(sum[i]>n-pos[i]+1){
            cout<<-1<<endl;
            return 0;
        }
        if(pos[i-1]<pos[i]-1){
            if(sum[i]>n-pos[i-1]){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    if(sum[1]!=n){
        cout<<-1<<endl;
        return 0;
    }
    int now=n;
    for(int i=m;i;i--){
        if(now>pos[i]){
            break;
        }
        now--;
    }
    ll ans=0;
    for(int i=m;i>=1;i--){
        if(pos[i]>=now){
            continue;
        }
        ans+=val[i]*(now-pos[i])-val[i]*(val[i]-1)/2;
        now-=val[i];
    }
    cout<<ans<<endl;
    return 0;
}