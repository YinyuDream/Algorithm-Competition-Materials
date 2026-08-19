#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n+1),sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    set<int> st;
    for(int i=0;i<=n;i++){
        st.insert(i);
    }
    cout<<fixed<<setprecision(10);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            st.erase(st.lower_bound(l),st.upper_bound(r-1));
        }else{
            int pos;
            cin>>pos;
            auto now=st.lower_bound(pos);
            int l=*prev(now),r=*now;
            cout<<(1.0*sum[r]-sum[l])/(r-l)<<endl;
        }
    }
    return 0;
}