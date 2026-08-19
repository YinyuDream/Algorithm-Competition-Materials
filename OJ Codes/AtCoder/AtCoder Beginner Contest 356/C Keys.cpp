#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,k,ans;
int a[maxn][maxn],t[maxn],r[maxn];
char c[maxn];
bool check(){
    int tot=0;
    for(int i=1;i<=m;i++){
        int cnt=0;
        for(int j=1;j<=t[i];j++){
            if(r[a[i][j]]==1)
                cnt++;
        }
        if(cnt<k&&c[i]=='x')
            tot++;
        if(cnt>=k&&c[i]=='o')
            tot++;
    }
    return tot==m;
}
void dfs(int x){
    if(x==n+1){
        if(check()){
            ans++;
        }
        return ;
    }
    r[x]=1;
    dfs(x+1);
    r[x]=0;
    dfs(x+1);
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>t[i];
        for(int j=1;j<=t[i];j++)
            cin>>a[i][j];
        cin>>c[i];
    }
    dfs(1);
    cout<<ans<<endl;
}