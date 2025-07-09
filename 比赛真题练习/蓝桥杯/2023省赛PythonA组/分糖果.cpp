#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,x,pos=1,lst=1;
char s[maxn],t[maxn];
int main(){
    cin>>n>>x>>(s+1);
    sort(s+1,s+n+1);
    for(int i=1;i<=x;i++)
        t[i]=s[i];
    if(t[x]!=t[1]){
        cout<<t[x];
        return 0;
    }
    cout<<t[1];
    for(int i=x+1;i<=n;i++)
        cout<<s[i];
    return 0;
}