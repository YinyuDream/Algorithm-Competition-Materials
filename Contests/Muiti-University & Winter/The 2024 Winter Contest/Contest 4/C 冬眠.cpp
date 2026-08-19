#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m,x,y,p,q;
char s[maxn][maxn];
int opt[maxn],pos[maxn];
int main(){
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        cin>>s[i]+1;
    }
    cin>>p>>q;
    for(int i=1,op,z;i<=q;i++){
        cin>>op>>z;
        opt[i]=op;
        pos[i]=z;
    }
    while(p--){
        for(int i=1;i<=q;i++){
            if(opt[i]==1){
                char lst=s[pos[i]][m];
                for(int j=m;j>=2;j--){
                    s[pos[i]][j]=s[pos[i]][j-1];
                }
                s[pos[i]][1]=lst;
            }else{
                char lst=s[n][pos[i]];
                for(int j=n;j>=2;j--){
                    s[j][pos[i]]=s[j-1][pos[i]];
                }
                s[1][pos[i]]=lst;
            }
        }
    }
    cout<<s[x][y];
    return 0;
}