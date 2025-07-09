#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n;
int a[maxn];
int b[maxn][maxn],c[maxn][maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j])
                b[i][a[j]]=1,c[j][a[i]]=1;
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            cout<<b[i][j]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            cout<<c[i][j]<<" ";
    return 0;
}