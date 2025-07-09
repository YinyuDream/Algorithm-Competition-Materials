#include<bits/stdc++.h>
using i64 = long long;
using namespace std;
char s[3000][3000];
int num[24];
int len=0;
int a,b;
int maxs=0;
void dfs(int pos){
    if(pos==7){
        if(len==a){
            for(int i=0;i<24;i++){
                num[i]=0;
            }
            for(int i=0;i<24;i++){
                for(int j=0;j<7;j++){
                    if(book[j][i]&&s[j][i]=='.'){
                        num[i]++;
                    }
                }
            }
            sort(num,num+24);
            int all=0;
            for(int i=24-1;i>=24-b;i--){
                all+=num[i];
            }
            maxs=max(maxs,all);
        }
        return;
    }
    book[pos]=0;
    dfs(pos+1);
    book[pos]=1;
    len++;
    dfs(pos+1);
    len--;
    book[pos]=0;
}
void solve(){
    int n=7;
    int m=24;
    for(int i=0;i<n;i++){
        num[i]=0;
        for(int j=0;j<m;j++){
            cin >> s[i][j];
        }
    }
    cin>>a>>b;
    int ena=b;
    dfs(0);
    cout<<setprecision(16)<<maxs*1.0/ena<<'\n';
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}