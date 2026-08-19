#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int T,n,m,bn,bm;
int a[maxn][maxn];
ll pw2[maxn];
int main(){
    pw2[0]=1;
    for(int i=1;i<=62;i++)
        pw2[i]=pw2[i-1]*2;
    cin>>T;
    while(T--){
        cin>>n>>m;
        cout<<n*m<<endl;
        bn=n/2+(n%2!=0);
        bm=m/2+(m%2!=0);
        int mn=-1;
        for(int i=1;i<=bn;i++){
            for(int j=1;j<=bm;j++){
                int x=2*(i-1)+1,y=2*(j-1)+1;
                a[x][y]=mn+4*(j-1)+1;
                a[x][y+1]=mn+4*(j-1)+2;
                a[x+1][y]=mn+4*(j-1)+3;
                a[x+1][y+1]=mn+4*(j-1)+4;
                if(j==bm){
                    int num=log2(a[x+1][y+1]-a[x][1])+1;
                    mn=pw2[num]+a[x][1]-1;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}