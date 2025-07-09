#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<string>> ord(q,vector<string>(n));
    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            cin>>ord[i][j];
        }
    }
    int find=0,mx=(1<<q)-1;
    for(int i=0;i<(1<<q);i++){
        vector<string> now(n,string(m,'0'));
        for(int j=0;j<q;j++){
            if((i>>j)&1){
                for(int k=0;k<n;k++){
                    for(int l=0;l<m;l++){
                        if(ord[j][k][l]=='1'){
                            now[k][l]='1';
                        }
                    }
                }
            }
        }
        bool check=true;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(v[j][k]==now[j][k]){
                    check=false;
                }
            }
        }
        if(check){
            find=1;
            if(__builtin_popcount(mx)>__builtin_popcount(i)){
                mx=i;
            }
        }
    }
    if(!find){
        cout<<"-1"<<endl;
    }else{
        cout<<__builtin_popcount(mx)<<endl;
        for(int i=0;i<q;i++){
            if((mx>>i)&1){
                cout<<i+1<<" ";
            }
        }
    }
    return 0;
}