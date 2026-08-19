#include<bits/stdc++.h>
using namespace std;
int a[11][11],b[11][11];
int ans;
bool check()
{
    for(int i=2;i<=5;i++){
        for(int j=1;j+i<=6;j++){
            if(b[i][j]==1){
                a[i][j]=a[i-1][j]&a[i-1][j+1];
            }else if(b[i][j]==2){
                a[i][j]=a[i-1][j]|a[i-1][j+1];
            }else{
                a[i][j]=a[i-1][j]^a[i-1][j+1];
            }
        }
    }
    return a[5][1]==1;
}
void dfs(int x,int y)
{
    if(x==6){
        if(check())ans++;
        return ;
    }
    b[x][y]=1;
    if(x+y==6)dfs(x+1,1);
    else dfs(x,y+1);
    b[x][y]=2;
    if(x+y==6)dfs(x+1,1);
    else dfs(x,y+1);
    b[x][y]=3;
    if(x+y==6)dfs(x+1,1);
    else dfs(x,y+1);
}
int main(){
    a[1][1]=1,a[1][2]=0,a[1][3]=1,a[1][4]=0,a[1][5]=1;
    dfs(2,1);
    cout<<ans<<endl;
    return 0;
}