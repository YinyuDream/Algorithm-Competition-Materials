#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            a[i][j]=ch-'0';
        }
    }
    int l=0,r=m-1,u=0,d=n-1;
    vector<vector<int>> num(max(n,m));
    while(l<r&&u<d){
        for(int i=l;i<=r;i++){
            num[l].push_back(a[u][i]);
        }
        for(int i=u+1;i<=d;i++){
            num[l].push_back(a[i][r]);
        }
        for(int i=r-1;i>=l;i--){
            num[l].push_back(a[d][i]);
        }
        for(int i=d-1;i>u;i--){
            num[l].push_back(a[i][l]);
        }
        for(int i=0;i<3;i++){
            num[l].push_back(num[l][i]);
        }
        l++,r--,u++,d--;
    }
    int ans=0;
    for(int i=0;i<l;i++){
        for(int j=0;j+3<num[i].size();j++){
            if(num[i][j]==1&&num[i][j+1]==5&&num[i][j+2]==4&&num[i][j+3]==3){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}