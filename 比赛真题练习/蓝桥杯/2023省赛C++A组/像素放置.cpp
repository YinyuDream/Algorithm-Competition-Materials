#include<bits/stdc++.h>
using namespace std;
const int maxn=11;
int n,m;
int ans[maxn][maxn];
char s[maxn][maxn];
bool can(int i,int j)
{
    if(!(s[i][j]>='0'&&s[i][j]<='9'))
        return true;
    return s[i][j]-'0'==ans[i][j]+ans[i+1][j]+ans[i+1][j+1]+ans[i][j+1]+ans[i-1][j+1]+ans[i-1][j]+ans[i-1][j-1]+ans[i][j-1]+ans[i+1][j-1];
}
bool check()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]>='0'&&s[i][j]<='9'){
                int num=s[i][j]-'0',tot=ans[i][j]+ans[i+1][j]+ans[i+1][j+1]+ans[i][j+1]+ans[i-1][j+1]+ans[i-1][j]+ans[i-1][j-1]+ans[i][j-1]+ans[i+1][j-1];
                if(tot!=num)
                    return false;
            }
        }
    }
    return true;
}
void dfs(int x,int y)
{
    if(x==n+1){
        if(check()){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++)
                    cout<<ans[i][j];
                cout<<endl;
            }
        }
        return ;
    }
    ans[x][y]=0;
    if((can(x-1,y-1)&&x>=2&&y>=2)||x<2||y<2){
        if(y==m)dfs(x+1,1);
        else dfs(x,y+1);
    }
    ans[x][y]=1;
    if((can(x-1,y-1)&&x>=2&&y>=2)||x<2||y<2){
        if(y==m)dfs(x+1,1);
        else dfs(x,y+1);
    }
    ans[x][y]=0;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>(s[i]+1);
    dfs(1,1);
    return 0;
}