#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
typedef long long ll;
int T,n,m;
int a[maxn][maxn];
vector<int> st[maxn][maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        st[1][1].push_back(a[1][1]);
        for(int i=2;i<=m;i++){
            for(auto &j:st[1][i-1])
                st[1][i].push_back(__gcd(j,a[1][i]));
            sort(st[1][i].begin(),st[1][i].end());
            st[1][i].erase(unique(st[1][i].begin(),st[1][i].end()),st[1][i].end());
        }
        for(int i=2;i<=n;i++){
            for(auto &j:st[i-1][1])
                st[i][1].push_back(__gcd(j,a[i][1]));
            sort(st[i][1].begin(),st[i][1].end());
            st[i][1].erase(unique(st[i][1].begin(),st[i][1].end()),st[i][1].end());
        }
        for(int i=2;i<=n;i++){
            for(int j=2;j<=m;j++){
                for(auto &k:st[i-1][j])
                    st[i][j].push_back(__gcd(k,a[i][j]));
                for(auto &k:st[i][j-1])
                    st[i][j].push_back(__gcd(k,a[i][j]));
                sort(st[i][j].begin(),st[i][j].end());
                st[i][j].erase(unique(st[i][j].begin(),st[i][j].end()),st[i][j].end());
            }
        }
        int ans=0;
        for(auto &i:st[n][m])
            ans=max(ans,i);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                st[i][j].clear();       
    }
    return 0;
}