#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const ll lim=1e9;
//vector<pair<ll,int>> edge[maxn];
void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<pair<ll,int>>> edge(n+1);
    vector<ll> t(n+1);
    vector<int> inf(n+1,0),book(n+1,0);
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==0){
            cin>>t[i];
        }else{
            int p;
            cin>>p;
            for(int j=0;j<p;j++){
                int x,y;
                cin>>x>>y;
                edge[i].push_back({x,y});
            }
        }
    }
    if(t[k]!=0){
        cout<<t[k]<<endl;
        return;
    }
    if(edge[k].size()==1){
        cout<<0<<endl;
        return;
    }
    int _=0;
    function<void(int)> dfs=[&](int u){
        _++;
        //if(_%1000==0) cout<<_<<endl;
        book[u]=1;
        for(auto [x,y]:edge[u]){
            if(book[y]) continue;
            dfs(y);
            if(inf[y]||t[y]*x>lim){
                inf[u]=1;
                return ;
            }
            t[u]+=t[y]*x;
            if(t[u]>lim){
                inf[u]=1;
                return ;
            }
        }
    };
    dfs(k);
    vector<ll> val;
    ll ans=0;
    int cnt=0;
    for(auto [x,y]:edge[k]){
        cout<<(inf[y]?-1:t[y]*x)<<'f\n';
        if(!inf[y]&&t[y]*x<=lim){
            val.push_back(t[y]*x);
            ans+=t[y]*x;
        }else{
            cnt++;
        }
    }
    cout<<endl;
    if(cnt>1){
        cout<<"Impossible"<<endl;
        return;
    }
    if(cnt==0){
        ans-=*max_element(val.begin(),val.end());
    }
    if(ans>lim) cout<<"Impossible";
    else cout<<ans;
    cout<<endl;
}
int main(){
    freopen("1009.in","r",stdin);
    //freopen("1009_my.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}