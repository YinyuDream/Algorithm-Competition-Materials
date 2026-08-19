#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),mn(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    mn[n]=a[n];
    for(int i=n-1;i>=1;i--){
        mn[i]=min(mn[i+1],a[i]);
    }
    vector<int> p,q;
    for(int i=n;i;i--){
        if(a[i]==mn[i]){
            p.push_back(a[i]);
        }
        else{
            q.push_back(a[i]+1);
        }
    }
    sort(p.begin(),p.end());
    if(q.empty()){
        for(auto x:p){
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    sort(q.begin(),q.end());
    for(auto x:q){
        p.push_back(x);
    }
    q=p;
    unique(q.begin(),q.end());
    map<int,int> ord;
    for(int i=0;i<n;i++){
        ord[p[i]]=lower_bound(q.begin(),q.end(),p[i])-q.begin();
    }
    
    vector<int> pos(n);
    iota(pos.begin(),pos.end(),0);
    sort(pos.begin(),pos.end(),[&](int i,int j){
        if(p[i]==p[j]){
            if(ord[i]&1==0){
                return i>j;
            }else{
                return i<j;
            }
        }
        return p[i]<p[j];
    });
    int tot=0;
    for(int i=0;i<n;i++){
        if(pos[i]<pos[i-1]){
            tot++;
        }
        cout<<p[pos[i]]+tot<<" ";
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}