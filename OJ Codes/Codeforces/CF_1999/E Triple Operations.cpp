#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+1;
vector<int> a(maxn),sum(maxn);
void init()
{
    auto work([&](int x){
        int res=0;
        while(x){
            x/=3;
            res++;
        }
        return res;
    });
    for(int i=1;i<maxn;i++)
        a[i]=work(i);
    for(int i=1;i<maxn;i++)
        sum[i]=sum[i-1]+a[i];
}
void solve(){
    int l,r;
    cin>>l>>r;
    cout<<a[l]*2+sum[r]-sum[l]<<endl;
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