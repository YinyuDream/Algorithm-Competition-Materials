#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> l(n+1),r(n+1);
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    int mn=1e9;
    for(int i=1;i<=n;i++){
        mn=min(mn,r[i]-l[i]+1);
    }
    if(mn>=k){
        cout<<"Yes"<<endl;
        for(int i=1;i<=n;i++){
            int val=l[i];
            while(val%k!=0){
                val++;
            }
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }
    int pos=0;
    for(int i=1;i<=n;i++){
        if(r[i]-l[i]+1==mn){
            pos=i;
            break;
        }
    }
    set<int> fac;
    for(int i=l[pos];i<=r[pos];i++){
        int val=i;
        for(int j=1;j*j<=val;j++){
            if(val%j==0){
                if(j>=k){
                    fac.insert(j);
                }
                if(val/j>=k){
                    fac.insert(val/j);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        vector<int> to_del;
        for(auto x:fac){
            int val=l[i]/x;
            if(val*x<l[i]){
                val++;
            }
            if(val*x>r[i]){
                to_del.push_back(x);
            }
        }
        for(auto x:to_del){
            fac.erase(x);
        }
    }
    if(fac.empty()){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
        int ans=*fac.begin();
        for(int i=1;i<=n;i++){
            int val=l[i]/ans;
            if(val*ans<l[i]){
                val++;
            }
            cout<<val*ans<<" ";
        }
        cout<<endl;
    }

}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}