#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,m;
unordered_set<int>st;
void solve()
{
    cin>>n>>m;
    st.clear();
    for(int i=1;i<=m;i++){
        if(st.find(n%i)==st.end())
            st.insert(n%i);
        else{
            cout<<"Yes"<<endl;
            return ;
        }
    }
    cout<<"No"<<endl;
    return ;
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}