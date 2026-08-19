#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(a[0]!=0){
        cout<<0<<endl;
        return;
    }
    if(x>=n){
        n=a.erase(unique(a.begin(),a.end()),a.end())-a.begin();
        for(int i=0;i<n;i++){
            if(a[i]!=i){
                cout<<i<<endl;
                return;
            }
        }
        cout<<n<<endl;
        return;
    }
    vector<vector<int>> val(x);
    for(int i=0;i<n;i++){
        val[a[i]%x].push_back(a[i]);
    }
    for(int i=0;i<x;i++){
        if(val[i].size()==0){
            continue;
        }
        int sz=val[i].size();
        for(int j=0;j<sz;j++){
            if(i+j*x>n){
                break;
            }
            if(val[i][j]<i+j*x){
                val[i][j]=i+j*x;
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<x;i++){
        for(int j=0;j<val[i].size();j++){
            ans.push_back(val[i][j]);
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(int i=0;i<ans.size();i++){
        if(ans[i]!=i){
            cout<<i<<endl;
            return;
        }
    }
    cout<<ans.size()<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}