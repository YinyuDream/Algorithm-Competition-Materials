#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    multiset<int> s;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    for(int i=1;i<n;i++){
        if(i%2==1){
            s.erase(s.begin());
        }else{
            s.erase(prev(s.end()));
        }
    }
    cout<<*s.begin()<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}