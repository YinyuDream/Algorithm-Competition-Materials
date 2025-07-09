#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    string a,b;
    cin>>a>>b;
    int n=a.size(),m=b.size();
    int l=0,r=min(n,m);
    auto can=[&](int pos,int len){
        int now=pos;
        for(int i=0;i<n;i++){
            if(b[now]==a[i]){
                now++;
            }
            if(now-pos==len)return true;
        }
        return false;
    };
    auto check=[&](int len){
        for(int i=0;i+len-1<m;i++){
            if(can(i,len)){
                return true;
            }
        }
        return false;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<n+(m-r)<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}