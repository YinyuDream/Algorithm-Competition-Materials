#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn],t[11];
int main(){
    cin>>(s+1)>>(t+1);
    for(int i=1;i<=3;i++)
        t[i]=t[i]-'A'+'a';
    if(t[3]=='x'){
        auto p1=strchr(s+1,t[1]);
        if(!p1){
            cout<<"No";
            return 0;
        }
        auto p2=strchr(p1+1,t[2]);
        if(p2)cout<<"Yes";
        else cout<<"No";
    }else{
        auto p1=strchr(s+1,t[1]);
        if(!p1){
            cout<<"No";
            return 0;
        }
        auto p2=strchr(p1+1,t[2]);
        if(!p2){
            cout<<"No";
            return 0;
        }
        auto p3=strchr(p2+1,t[3]);
        if(p3)
            cout<<"Yes";
        else
            cout<<"No";
    }
    return 0;
}