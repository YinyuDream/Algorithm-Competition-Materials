#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n;
char a[maxn][maxn],b[maxn][maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]+1;
    for(int i=1;i<=n;i++)
        cin>>b[i]+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]!=b[i][j]){
                cout<<i<<' '<<j<<endl;
                return 0;
            }
    return 0;
}