#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> v(n+2);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i]="#"+v[i];
    }
    v[0]=string(m+1,'#');
    v[n+1]=string(m+1,'#');
    for(int i=1;i<=n;i++){
        int pos=v[i].find('H');
        if(pos!=string::npos){
            int cnt=count(v[i].begin()+1,v[i].begin()+pos+1,'A');
            for(int j=1;j<=cnt;j++){
                v[i][j]='A';
            }
            for(int j=cnt+1;j<pos;j++){
                v[i][j]='#';
            }
            cnt=count(v[i].begin()+pos+1,v[i].end(),'B');
            for(int j=m;j>m-cnt;j--){
                v[i][j]='B';
            }
            for(int j=m-cnt;j>pos;j--){
                v[i][j]='#';
            }
        }else{
            int cnt_A=count(v[i].begin()+1,v[i].end(),'A');
            int cnt_B=count(v[i].begin()+1,v[i].end(),'B');
            if(cnt_A==cnt_B){
                for(int j=1;j<=m;j++){
                    v[i][j]='#';
                }
            }else if(cnt_A>cnt_B){
                int delta=cnt_A;
                for(int j=m;j>m-delta;j--){
                    v[i][j]='A';
                }
                for(int j=m-delta;j>0;j--){
                    v[i][j]='#';
                }
            }else{
                int delta=cnt_B;
                for(int j=1;j<=delta;j++){
                    v[i][j]='B';
                }
                for(int j=delta+1;j<=m;j++){
                    v[i][j]='#';
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((v[i][j]=='A'||v[i][j]=='B')&&(v[i][j]==v[i+1][j]||v[i][j]==v[i-1][j])){
                cout<<"#";
            }else{
                cout<<v[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}