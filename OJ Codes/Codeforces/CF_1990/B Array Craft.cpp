#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n+1);
    int len=x-y+1;
    for(int i=y;i<=x;i++)
        a[i]=1;
    for(int i=y-1;i>=max(y-len+1,1);i--)
        a[i]=-1;
    for(int i=x+1;i<=min(x+len-1,n);i++)
        a[i]=-1;
    for(int i=y-len,val=1;i>=1;i--){
        a[i]=val;
        val=-val;
    }
    for(int i=x+len,val=1;i<=n;i++){
        a[i]=val;
        val=-val;
    }
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}