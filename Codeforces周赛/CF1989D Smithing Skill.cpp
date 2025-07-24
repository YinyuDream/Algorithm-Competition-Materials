#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int a,b;
};
bool cmp(node x,node y){
    if(x.a-x.b==y.a-y.b){
        return x.a<y.a;
    }
    return x.a-x.b<y.a-y.b;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<node> t(n+1),t2;
    vector<int> c(m+1);
    for(int i=1;i<=n;i++)
        cin>>t[i].a;
    for(int i=1;i<=n;i++)
        cin>>t[i].b;
    for(int i=1;i<=m;i++)
        cin>>c[i];
    sort(t.begin()+1,t.end(),cmp);
    t2.push_back(t[1]);
    for(int i=2;i<=n;i++){
        if(t[i].a<t2.back().a){
            t2.push_back(t[i]);
        }
    }
    ll ans=0;
    auto work=[&](int x){
        ll val=0;
        for(auto &i:t2){
            if(x<i.a)continue;
            int tot=(x-i.a)/(i.a-i.b)+1;
            x-=tot*(i.a-i.b);
            val+=tot*2;
        }
        return val;
    };
    for(int i=1;i<=m;i++)
        ans+=work(c[i]);
    cout<<ans<<endl;
}
int main(){
    int T=1;
    while(T--){
        solve();
    }
    return 0;
}