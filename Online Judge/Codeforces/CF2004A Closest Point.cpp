#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    if(s.size()>2){
        cout<<"NO"<<endl;
    }else{
        if(s.size()==1){
            cout<<"YES"<<endl;
        }else if(s.size()==2){
            if(*s.begin()+1<*s.rbegin()){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
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