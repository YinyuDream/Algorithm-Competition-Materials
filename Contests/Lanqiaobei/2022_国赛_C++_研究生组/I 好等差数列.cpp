#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10,maxa=1e4+10;
int n,m;
int a[maxn],f[maxn][maxa],lst[maxn][maxa];
void work(int eth){
    int ans=n-1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<maxn;j++)
            f[i][j]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[i]-a[j]>=0&&(a[i]-a[j])%(i-j)==0){
                /*if(lst[j][(a[i]-a[j])/(i-j)]<eth){
                    lst[j][(a[i]-a[j])/(i-j)]=eth;
                    f[j][(a[i]-a[j])/(i-j)]=1;
                }
                if(lst[i][(a[i]-a[j])/(i-j)]<eth){
                    lst[i][(a[i]-a[j])/(i-j)]=eth;
                    f[i][(a[i]-a[j])/(i-j)]=1;
                }*/
                f[i][(a[i]-a[j])/(i-j)]=max(f[i][(a[i]-a[j])/(i-j)],f[j][(a[i]-a[j])/(i-j)]+1);
                ans=min(ans,n-f[i][(a[i]-a[j])/(i-j)]);
            }
    eth++;
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int j=0;j<maxn;j++)
            f[i][j]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[i]-a[j]>=0&&(a[i]-a[j])%(i-j)==0){
                /*if(lst[j][(a[i]-a[j])/(i-j)]<eth){
                    lst[j][(a[i]-a[j])/(i-j)]=eth;
                    f[j][(a[i]-a[j])/(i-j)]=1;
                }
                if(lst[i][(a[i]-a[j])/(i-j)]<eth){
                    lst[i][(a[i]-a[j])/(i-j)]=eth;
                    f[i][(a[i]-a[j])/(i-j)]=1;
                }*/
                f[i][(a[i]-a[j])/(i-j)]=max(f[i][(a[i]-a[j])/(i-j)],f[j][(a[i]-a[j])/(i-j)]+1);
                ans=min(ans,n-f[i][(a[i]-a[j])/(i-j)]);
            }
    reverse(a+1,a+n+1);
    cout<<ans<<" ";
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        a[++u]=v;
        work(m*2-1);
    }
    return 0;
}