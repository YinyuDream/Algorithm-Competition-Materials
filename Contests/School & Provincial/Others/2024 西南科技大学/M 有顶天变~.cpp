#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+2);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[n+1]=*max_element(a.begin()+1,a.end());
    stack<int> st;
    long long ans=0;
    for(int i=1;i<=n+1;i++){
        if(st.size()){
            if(st.top()<a[i]){
                ans+=a[i]-st.top();
            }
            while(st.size()&&st.top()<a[i]){
                st.pop();
            }
        }
        st.push(a[i]);
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