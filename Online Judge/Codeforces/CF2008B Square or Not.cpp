#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int v=sqrt(n);
    if(v*v!=n){
        cout<<"NO"<<endl;
    }else{
        vector<vector<int>> a(v,vector<int>(v,0));
        int tot=0;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                a[i][j]=s[i*v+j]-'0';
                tot+=a[i][j];
            }
        }
        int val=0;
        for(int i=0;i<v;i++){
            val+=a[0][i];
            val+=a[v-1][i];
        }
        for(int i=1;i<v-1;i++){
            val+=a[i][0];
            val+=a[i][v-1];
        }
        if(tot==val&&val==v*4-4){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
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