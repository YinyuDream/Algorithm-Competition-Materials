#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int l,r;
    cin>>l>>r;
    vector<int> v;
    for(int i=l;i<=r;i++)
        v.push_back(i);
    int n=v.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        if(i+2>=n){
            break;
        }
        if(__gcd(v[i],v[i+1])==1&&__gcd(v[i+1],v[i+2])==1&&__gcd(v[i],v[i+2])==1){
            cnt++;
            i=i+2;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}