#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    vector<int> v(n);
    int now=p;
    for(int i=0;i<n;i++){
        if(now>m){
            now-=m;
            v[i]=m;
        }else{
            v[i]=now;
            now=0;
            break;
        }
    }
    now=p;
    bool a=m-*min_element(v.begin(),v.end())>=k;
    bool b=m-p/n>=k;
    if(b){
        cout<<"Together"<<endl;
    }else if(a){
        cout<<"Chance"<<endl;
    }else{
        cout<<"Divide"<<endl;
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