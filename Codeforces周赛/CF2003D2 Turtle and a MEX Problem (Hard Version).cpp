#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n);
    vector<int> mex(n);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        a[i].resize(k);
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
        sort(a[i].begin(),a[i].end());
        auto it=unique(a[i].begin(),a[i].end());
        a[i].erase(it,a[i].end());
        int pos=-1;
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]-j>=2){
                pos=j;
                break;
            }
        }
        if(pos!=-1){
            a[i].erase(a[i].begin()+pos,a[i].end());
            a[i].push_back(2);
        }
        mex[i]=0;
        while(mex[i]<a[i].size()&&a[i][mex[i]]==mex[i]){
            mex[i]++;
        }
    }
    vector<int> ord(n);
    for(int i=0;i<n;i++){
        ord[i]=i;
    }
    sort(ord.begin(),ord.end(),[&](int x,int y){
        return a[x].back()<a[y].back();
    });
    ll ans=0;
    auto MEX=[&](int x,vector<int> &a){
        vector<int> b=a;
        b.push_back(x);
        sort(b.begin(),b.end());
        auto it=unique(b.begin(),b.end());
        b.erase(it,b.end());
        int res=0;
        while(res<b.size()&&b[res]==res){
            res++;
        }
        return res;
    };
    auto work=[&](int x){
        int mx=x;
        for(int i=0;i<n;i++){
            x=MEX(x,a[ord[i]]);
            mx=max(mx,x);
        }
        return mx;
    };
    for(int i=0;i<=m;i++){
        cout<<i<<":"<<work(i)<<endl;
        ans+=work(i);
    }
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