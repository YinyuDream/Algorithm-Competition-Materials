#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,m;
int a[maxn][maxn];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int _x1,_y1,_x2,_y2;
        cin>>_x1>>_y1>>_x2>>_y2;
        a[_x1][_y1]^=1;
        a[_x2+1][_y1]^=1;
        a[_x1][_y2+1]^=1;
        a[_x2+1][_y2+1]^=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]^=a[i-1][j]^a[i][j-1]^a[i-1][j-1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}