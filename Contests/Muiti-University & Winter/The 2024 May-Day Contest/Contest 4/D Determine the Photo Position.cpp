#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+10;
int n,m,ans;
int a[maxn][maxn];
string s;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char ch=getchar();
            while(ch!='0'&&ch!='1')
                ch=getchar();
            a[i][j]=ch-'0';
        }
    }
    cin>>s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]+=a[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j<=n;j++){
            if(a[i][j]==a[i][j-m]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}