#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    vector<int> R(n+1),C(n+1);
    int x,y;
    cin>>x>>y;
    for(int i=1;i<=n;i++){
        R[i]=a[x][i];
        C[i]=a[i][y];
    }
    for(int i=1;i<=n;i++){
        a[i][y]=R[i];
        a[x][i]=C[i];
    }
    a[x][y]=(R[x]+C[y])/2+((R[x]+C[y])%2!=0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" \n"[j==n];
    return 0;
}