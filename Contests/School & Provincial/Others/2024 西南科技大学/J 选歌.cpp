#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
void solve(){
    int n,hp;
    cin>>n>>hp;
    vector<pii> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(),a.end(),[&](pii u,pii v){
        if(u.first!=v.first){
            return u.first>v.first;
        }
        return u.second<v.second;
    });
    for(int i=0;i<n;i++){
        if(a[i].first<hp){
            hp-=a[i].first;
        }else{
            cout<<"YES"<<endl;
            cout<<i+1<<endl;
            for(int j=0;j<=i;j++){
                cout<<a[j].second<<" ";
            }
            cout<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}