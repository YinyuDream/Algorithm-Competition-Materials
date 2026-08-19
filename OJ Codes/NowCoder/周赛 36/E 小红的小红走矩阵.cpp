#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,rev;
int ans[maxn][maxn];
int main(){
    cin>>n>>m;
    if(m>n){
        swap(m,n);
        rev=1;
    }
    if(n>=5){
        for(int i=1;i<=m;i++)
            ans[1][i]=i%2;
        for(int i=1;i<m;i++)
            ans[2][i]=ans[3][i]=2;
        ans[2][m]=ans[1][m]^1;
        ans[3][m]=ans[2][m]^1;
        ans[4][m]=ans[3][m]^1;
        for(int i=m-1;i>=1;i--)
            ans[4][i]=ans[4][i+1]^1;
        for(int i=2;i<=m;i++)
            ans[5][i]=ans[4][i];
        ans[5][1]=2;
        for(int i=6;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans[i][j]=rand()%26;
    }else if(n==4){
        ans[1][1]=1,ans[1][2]=1,ans[1][3]=2;
        ans[2][1]=2,ans[2][2]=3,ans[2][3]=3;
        ans[3][1]=2,ans[3][2]=3,ans[3][3]=5;
        ans[4][1]=3,ans[4][2]=4,ans[4][3]=5;
        if(m==4){
            ans[1][4]=2,ans[2][4]=3,ans[3][4]=5,ans[4][4]=6;
        }
    }else{
        ans[1][1]=1,ans[1][2]=2,ans[1][3]=1;
        ans[2][1]=1,ans[2][2]=3,ans[2][3]=2;
        ans[3][1]=2,ans[3][2]=3,ans[3][3]=2;
    }
    if(rev==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                cout<<char(ans[i][j]+'a');
            cout<<endl;
        }
    }else{
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++)
                cout<<char(ans[j][i]+'a');
            cout<<endl;
        }
    }
}