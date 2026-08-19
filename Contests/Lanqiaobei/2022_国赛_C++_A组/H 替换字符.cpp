#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int m;
char s[maxn];
int main(){
    cin>>(s+1)>>m;
    for(int i=1;i<=m;i++){
        int l,r;
        char u,v;
        cin>>l>>r>>u>>v;
        for(int i=l;i<=r;i++)
            if(s[i]==u)
                s[i]=v;
    }
    cout<<s+1;
    return 0;
}