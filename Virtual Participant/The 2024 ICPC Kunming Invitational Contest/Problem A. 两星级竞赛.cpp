#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> s(n+1);
    vector<vector<int>> p(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        cin>>s[i];
        for(int j=1;j<=m;j++){
            cin>>p[i][j];
        }
    }
    vector<int> ord(n+1);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin()+1,ord.end(),[&](int i,int j){
        return s[i]>s[j];
    });
    vector<ll> mn(n+1);
    mn[0]=1e18;
    int pos=0;
    for(int i=1;i<=n;i++){
        ll sum=0;
        for(int j=1;j<=m;j++){
            if(p[ord[i]][j]!=-1){
                sum+=p[ord[i]][j];
            }
        }
        while(s[ord[pos+1]]>s[ord[i]]){
            pos++;
        }
        if(sum>=mn[ord[pos]]){
            cout<<"No"<<endl;
            return ;
        }
        ll delta=mn[ord[pos]]-sum-1;
        for(int j=1;j<=m;j++){
            if(p[ord[i]][j]==-1){
                if(delta>k){
                    p[ord[i]][j]=k;
                    delta-=k;
                }else{
                    p[ord[i]][j]=delta;
                    delta=0;
                }
            }
            mn[ord[i]]+=p[ord[i]][j];
        }
        mn[ord[i]]=min(mn[ord[i]],mn[ord[i-1]]);
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
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