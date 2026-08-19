#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n*m+1,0);
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    if(n==1&&m==1){
        cout<<-1<<endl;
        return;
    }
    int t=a[1];
    for(int i=1;i<n*m;i++)
        a[i]=a[i+1];
    a[n*m]=t;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cout<<a[(i-1)*m+j]<<" \n"[j==m];
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}