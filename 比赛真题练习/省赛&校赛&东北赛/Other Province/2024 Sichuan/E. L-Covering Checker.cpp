#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,cnt=0;
    cin>>n>>m;
    vector<vector<char>> a(n+2,vector<char>(m+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch=getchar();
            while(ch!='C'&&ch!='U'&&ch!='D'&&ch!='L'&&ch!='R'&&ch!='.')
                ch=getchar();
            a[i][j]=ch;
            cnt+=(ch=='.');
        }
    }
    if(cnt!=1){
        cout<<"No"<<endl;
        return;
    }
    if(cnt==1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]=='.'){
                    if(i!=1||j!=m){
                        cout<<"No"<<endl;
                        return;
                    }
                }
            }
        }
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='C'){
                int cnt=0;
                if(a[i+1][j]=='U')
                    cnt++;
                if(a[i-1][j]=='D')
                    cnt++;
                if(a[i][j+1]=='L')
                    cnt++;
                if(a[i][j-1]=='R')
                    cnt++;
                if(cnt!=2)
                    flag=false;
            }
        }
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}