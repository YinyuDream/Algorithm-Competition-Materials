#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,k;
    ll tot=0,sum=0;
    cin>>n>>m>>k;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    vector<vector<int>> b(n+1,vector<int>(m+1));
    vector<vector<int>> cnt(n+1,vector<int>(m+1));
    auto get=[&](int x1,int y1,int x2,int y2){
        return cnt[x2][y2]-cnt[x1-1][y2]-cnt[x2][y1-1]+cnt[x1-1][y1-1];
    };
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            b[i][j]=s[j-1]-'0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt[i][j]=b[i][j]-cnt[i-1][j-1]+cnt[i-1][j]+cnt[i][j-1];
            sum+=a[i][j]*b[i][j];
            tot+=a[i][j];
        }
    }
    ll p=sum-(tot-sum);
    if(p==0){
        cout<<"YES"<<endl;
        return;
    }
    vector<int> val;
    for(int i=1;i+k-1<=n;i++){
        for(int j=1;j+k-1<=m;j++){
            int x1=i,y1=j,x2=i+k-1,y2=j+k-1;
            int cur=get(x1,y1,x2,y2);
            int area=(x2-x1+1)*(y2-y1+1);
            int delta=(area-cur)-cur;
            if(delta!=0){
                val.push_back(delta);
            }
        }
    }
    if(val.empty()){
        cout<<"NO"<<endl;
        return;
    }
    int gcd=val[0];
    for(auto x:val){
        gcd=__gcd(gcd,x);
    }
    if(p%gcd==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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