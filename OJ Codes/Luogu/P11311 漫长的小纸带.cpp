#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    n=unique(a.begin()+1,a.end())-a.begin()-1;
    int lim=sqrt(n+1);
    vector<int> f(n+1,1e9);
    map<int,int> mp;
    set<int> st;
    st.insert(0);
    f[0]=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        if(mp.find(a[i])==mp.end()){
            mp[a[i]]=i;
            st.insert(-i);
        }else{
            st.erase(-mp[a[i]]);
            mp[a[i]]=i;
            st.insert(-i);
        }
        for(auto pos:st){
            if(cnt>lim){
                break;
            }
            f[i]=min(f[i],f[-pos]+cnt*cnt);
            cnt++;
        }
    }
    cout<<f[n]<<endl;
}
int main(){
    solve();
    return 0;
}