#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,tot;
    cin>>n;
    if(n<3){
        for(int i=2;i<=n+1;i++){
            cout<<1<<" "<<i<<endl;
        }
        return;
    }
    vector<vector<int>> a(n/3+4,vector<int>(n/3+4,0));
    if(n/3>=1){
        a[1][n/3+1]=a[1][n/3+2]=a[1][n/3+3]=1;
        a[n/3+1][1]=a[n/3+2][1]=a[n/3+3][1]=1;
    }
    if(n/3>=2){
        a[2][1]=a[2][n/3+1]=a[2][n/3+2]=1;
        a[1][2]=a[n/3+1][2]=a[n/3+2][2]=1;
    }
    if(n/3>=3){
        a[3][1]=a[3][2]=a[3][n/3+1]=1;
        a[1][3]=a[2][3]=a[n/3+1][3]=1;
    }
    for(int i=4;i<=n/3;i++){
        a[i][1]=a[i][2]=a[i][3]=1;
        a[1][i]=a[2][i]=a[3][i]=1;
    }
    int rem=n%3;
    for(int i=1;i<=n/3+3;i++){
        if(a[1][i]==1){
            cout<<1<<" "<<i<<endl;
        }
    }
    for(int i=n/3+4;i<=n/3+3+rem;i++){
            cout<<1<<" "<<i<<endl;
    }
    for(int i=2;i<=n/3+3;i++){
        for(int j=i+1;j<=n/3+3;j++){
            if(a[i][j]==1){
                cout<<i<<" "<<j<<endl;
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