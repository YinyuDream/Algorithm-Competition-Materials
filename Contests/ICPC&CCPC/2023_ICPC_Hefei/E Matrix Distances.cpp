#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,cnt;
long long ans;
int pos[maxn*maxn];
struct node{
    int x,y,col;
}a[maxn*maxn];
bool operator<(node a,node b)
{
    return a.col<b.col;
}
bool cmp_x(node a,node b)
{
    return a.x<b.x;
}
bool cmp_y(node a,node b)
{
    return a.y<b.y;
}
int dis(node a,node b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
    cin>>n>>m;
    for(int i=1,col;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>col;
            a[(i-1)*m+j]={i,j,col};
        }
    }
    sort(a+1,a+n*m+1);
    pos[++cnt]=1;
    for(int i=1;i<n*m;i++){
        if(a[i].col!=a[i+1].col){
            pos[++cnt]=i+1;
        }
    }
    pos[++cnt]=n*m+1;
    for(int i=1;i<cnt;i++){
        int len=pos[i+1]-pos[i];
        sort(a+pos[i],a+pos[i+1],cmp_x);
        for(int j=pos[i];j<pos[i+1];j++){
            ans+=(1ll-len+(j-pos[i])*2)*a[j].x;
        }
        sort(a+pos[i],a+pos[i+1],cmp_y);
        for(int j=pos[i];j<pos[i+1];j++){
            ans+=(1ll-len+(j-pos[i])*2)*a[j].y;
        }
    }
    cout<<ans*2<<endl;
    return 0;
}