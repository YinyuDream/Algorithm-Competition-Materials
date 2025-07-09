#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=31;
int T,x,y,z;
int a[maxn][maxn][maxn];
int main(){
    memset(a,-1,sizeof(a));
    a[0][0][0]=0;
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            for(int k=0;k<maxn;k++){
                if(i-2>=0&&a[i-2][j][k]!=-1) a[i][j][k]=max(a[i][j][k],a[i-2][j][k]);
                if(j-2>=0&&a[i][j-2][k]!=-1) a[i][j][k]=max(a[i][j][k],a[i][j-2][k]);
                if(k-2>=0&&a[i][j][k-2]!=-1) a[i][j][k]=max(a[i][j][k],a[i][j][k-2]);
                if(i-1>=0&&j-1>=0&&a[i-1][j-1][k]!=-1) a[i][j][k]=max(a[i][j][k],a[i-1][j-1][k]+1);
                if(i-1>=0&&k-1>=0&&a[i-1][j][k-1]!=-1) a[i][j][k]=max(a[i][j][k],a[i-1][j][k-1]+1);
                if(j-1>=0&&k-1>=0&&a[i][j-1][k-1]!=-1) a[i][j][k]=max(a[i][j][k],a[i][j-1][k-1]+1);
            }
        }
    }
    cin>>T;
    while(T--){
        cin>>x>>y>>z;
        if(a[x][y][z]>=0) cout<<a[x][y][z]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}