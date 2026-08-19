#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10,p=1e9+7;
int n,ans;
int a[maxn];
int f[maxn][11][11][11];
void work(int u,int v,int w)
{
    memset(f,0,sizeof f);
    f[3][u][v][w]=1;
    for(int i=4;i<=n+3;i++)
        for(int a4=0;a4<=10;a4++)
            for(int a3=0;max(a3,a4)<=a[i];a3++)
                for(int a2=0;a2<=10;a2++)
                    if(max(a2,max(a3,a4))==a[i-1])
                        for(int a1=0;a1<=10;a1++)
                            f[i][a2][a3][a4]=(f[i][a2][a3][a4]+f[i-1][a1][a2][a3])%p;
    ans=(ans+f[n+3][u][v][w])%p;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[n+1]=a[1],a[n+2]=a[2],a[n+3]=a[3];
    for(int k=0;k<=10;k++)
        for(int j=0;max(j,k)<=a[3];j++)
            for(int i=0;i<=10;i++)
                if(max(i,max(j,k))==a[2])
                    work(i,j,k);
    cout<<ans<<endl;
    return 0;
}