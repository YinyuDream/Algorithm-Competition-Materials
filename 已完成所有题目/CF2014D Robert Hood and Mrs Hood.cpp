#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,d,k;
    cin>>n>>d>>k;
    vector<vector<int>> a(n+1),b(n+1);
    for(int i=1;i<=k;i++){
        int l,r;
        cin>>l>>r;
        a[l].push_back(i);
        b[r].push_back(i);
    }
    set<int> st;
    for(int i=1;i<=d;i++){
        for(auto x:a[i]){
            st.insert(x);
        }
    }
    int mn=0,mxx=0,mnval=INT_MAX,mxval=INT_MIN;
    for(int i=1;i+d-1<=n;i++){
        int val=st.size();
        if(val<mnval){
            mnval=val;
            mn=i;
        }
        if(val>mxval){
            mxval=val;
            mxx=i;
        }
        for(auto x:b[i]){
            st.erase(x);
        }
        if(i+d<=n){
            for(auto x:a[i+d]){
                st.insert(x);
            }
        }
    }
    cout<<mxx<<" "<<mn<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}