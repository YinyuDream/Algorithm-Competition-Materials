#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> fa(n+1),sz(n+1,1);
    iota(fa.begin(),fa.end(),0);
    int cnt=n;
    function<int(int)> find=[&](int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    };
    auto merge=[&](int x,int y){
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy){
            if(sz[fx]<sz[fy]){
                swap(fx,fy);
            }
            fa[fx]=fy;
            sz[fy]+=sz[fx];
            cnt--;
        }
    };
    vector<vector<set<int>>> st(11,vector<set<int>>(11));
    for(int i=1;i<=10;i++){//d
        for(int j=1;j<=i;j++){//a1
            for(int k=0;j+k*i<=n;k++){
                st[i][j].insert(j+k*i);
            }
        }
    }
    for(int i=1;i<=m;i++){
        int a,d,k;
        cin>>a>>d>>k;
        int a1=a%d;
        if(a1==0){
            a1=d;
        }
        auto &v=st[d][a1];
        int l=a,r=a+k*d;
        auto it=v.lower_bound(l);
        vector<int> tmp;
        while(it!=v.end()&&*it<=r){
            merge(a,*it);
            tmp.push_back(*it);
            it++;
        }
        for(auto x:tmp){
            st[d][a1].erase(x);
        }
        if(tmp.size()){
            st[d][a1].insert(tmp.front());
            st[d][a1].insert(tmp.back());
        }
    }
    cout<<cnt<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}