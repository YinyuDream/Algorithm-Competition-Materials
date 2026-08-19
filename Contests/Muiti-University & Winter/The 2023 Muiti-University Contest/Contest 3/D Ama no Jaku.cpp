#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n;
int a[maxn][maxn],b[maxn][maxn];
bool check(int x){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(b[i][j]!=x)
                return false;
    return true;
}
void copy(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            b[i][j]=a[i][j];
}
void opera(int id,int opt)
{
    if(opt==1){
        for(int i=1;i<=n;i++){
            b[id][i]^=1;
        }
    }else{
        for(int i=1;i<=n;i++){
            b[i][id]^=1;
        }
    }
}
int work(){
    copy();
    int col=b[1][1],ans=0x7f7f7f7f,cnt=0;
    for(int i=2;i<=n;i++)
        if(b[i][1]!=col)
            opera(i,1),cnt++;
    for(int i=2;i<=n;i++)
        if(b[1][i]!=col)
            opera(i,2),cnt++;
    if(check(col))ans=min(ans,cnt);
    
    cnt=1;
    copy();
    for(int i=1;i<=n;i++)
        b[1][i]^=1;
    col=b[1][1];
    for(int i=2;i<=n;i++)
        if(b[i][1]!=col)
            opera(i,1),cnt++;
    for(int i=2;i<=n;i++)
        if(b[1][i]!=col)
            opera(i,2),cnt++;
    if(check(col))ans=min(ans,cnt);
    
    cnt=1;
    copy();
    for(int i=1;i<=n;i++)
        b[i][1]^=1;
    col=b[1][1];
    for(int i=2;i<=n;i++)
        if(b[i][1]!=col)
            opera(i,1),cnt++;
    for(int i=2;i<=n;i++)
        if(b[1][i]!=col)
            opera(i,2),cnt++;
    if(check(col))ans=min(ans,cnt);
    
    cnt=2;
    copy();
    for(int i=1;i<=n;i++)
        b[i][1]^=1;
    for(int i=1;i<=n;i++)
        b[1][i]^=1;
    col=b[1][1];
    for(int i=2;i<=n;i++)
        if(b[i][1]!=col)
            opera(i,1),cnt++;
    for(int i=2;i<=n;i++)
        if(b[1][i]!=col)
            opera(i,2),cnt++;
    if(check(col))ans=min(ans,cnt);
    
    if(ans!=0x7f7f7f7f)return ans;
    else return -1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            char ch=getchar();
            while(ch<'0'||ch>'9'){
                ch=getchar();
            }
            a[i][j]=ch-'0';
        }
    cout<<work();
    return 0;
}