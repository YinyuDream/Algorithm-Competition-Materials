#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> b(m+1);
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    sort(b.begin()+1,b.end());
    auto work=[&](int x){
        if(x<b[1]){
            return b[1]-1;
        }else if(x>b[m]){
            return n-b[m];
        }else{
            int pos=lower_bound(b.begin()+1,b.end(),x)-b.begin();
            int d1=x-b[pos-1],d2=b[pos]-x,ans=0;
            if(d1<d2){
                swap(d1,d2);
            }
            if(d1>d2+1){
                ans+=((d1-(d2+1))/2)+((d1-(d2+1))%2);
            }
            ans+=d2;
            return ans;
        }
    };
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        cout<<work(x)<<endl;
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