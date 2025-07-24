#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int top=0;
int a[maxn];
void init()
{
    int now=0,mx=1e9,delta=1;
    while(true){
        if(now+delta<=mx){
            a[++top]=now+delta;
            now+=delta;
            delta++;
        }else{
            break;
        }
    }
}
void solve(){
    int l,r;
    cin>>l>>r;
    r-=l;
    cout<<upper_bound(a+1,a+top+1,r)-a<<endl;
}
int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}