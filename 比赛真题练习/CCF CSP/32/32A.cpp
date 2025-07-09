#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n,m;
int a[maxn][11];
int cmp(int u,int v)
{
    int cnt_1=0,cnt_2=0;
    for(int i=1;i<=m;i++){
        if(a[u][i]<a[v][i])
            cnt_1++;
        if(a[u][i]>a[v][i])
            cnt_2++;
    }
    if(cnt_1==m)
        return 1;
    if(cnt_2==m)
        return -1;
    return 0;
}
int fa[maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            int bigger=cmp(i,j);
            if(bigger==1){
                if(fa[i]==0){
                    fa[i]=j;
                }else{
                    fa[i]=min(fa[i],j);
                }
            }
            if(bigger==-1){
                if(fa[j]==0){
                    fa[j]=i;
                }else{
                    fa[j]=min(fa[j],i);
                }
            }
        }
    for(int i=1;i<=n;i++){
        cout<<fa[i]<<endl;
    }
    return 0;
}