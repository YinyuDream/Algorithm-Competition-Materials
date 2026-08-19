#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<int>> b(n,vector<int>(m));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            a[i][j]=s[j]-'0';
        }
    }
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            b[i][j]=s[j]-'0';
        }
    }
    int res_a=0,res_b=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            (res_a+=a[i][j])%=3,(res_b+=b[i][j])%=3;
    if(res_a!=res_b){
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++){
            if(a[i][j]!=b[i][j]){
                int _a=a[i][j],_b=b[i][j];
                if(_b<_a)
                    _b+=3;
                int diff=_b-_a;
                (a[i][j]+=diff)%=3;
                (a[i+1][j+1]+=diff)%=3;
                (a[i+1][j]+=3-diff)%=3;
                (a[i][j+1]+=3-diff)%=3;
            }
        }
    bool flag=true;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]!=b[i][j]){
                flag=false;
                break;
            }
    if(flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}