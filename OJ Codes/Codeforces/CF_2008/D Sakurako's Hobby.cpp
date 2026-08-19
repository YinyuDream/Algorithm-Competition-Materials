#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),fa(n+1),sz(n+1);
    string s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fa[i]=i;
    }
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++)
        if(s[i]=='0')
            sz[i]=1;
    function<int(int)> find=[&](int x){
        return x==fa[x]?x:fa[x]=find(fa[x]);
    };
    auto merge=[&](int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return;
        }
        if(sz[x]<sz[y]){
            swap(x,y);
        }
        sz[x]+=sz[y];
        fa[y]=x;
    };
    for(int i=1;i<=n;i++){
        merge(i,a[i]);
    }
    for(int i=1;i<=n;i++){
        cout<<sz[find(i)]<<" ";
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