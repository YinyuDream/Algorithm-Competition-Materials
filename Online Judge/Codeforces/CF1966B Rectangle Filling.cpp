#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
int T,n,m;
int a[maxn][maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char ch=getchar();
                while(ch!='W'&&ch!='B')
                    ch=getchar();
                a[i][j]=(ch=='W'?1:0);
            }
        }
        bool flag_1=true,flag_2=true;
        for(int i=2;i<=m;i++){
            if(a[1][1]!=a[1][i])
                flag_1=false;
            if(a[n][1]!=a[n][i])
                flag_2=false;
        }
        if(flag_1&&flag_2&&a[1][1]!=a[n][1]){
            cout<<"NO"<<endl;
            continue;
        }
        flag_1=true,flag_2=true;
        for(int i=2;i<=n;i++){
            if(a[1][1]!=a[i][1])
                flag_1=false;
            if(a[1][m]!=a[i][m])
                flag_2=false;
        }
        if(flag_1&&flag_2&&a[1][1]!=a[1][m]){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }
    return 0;
}