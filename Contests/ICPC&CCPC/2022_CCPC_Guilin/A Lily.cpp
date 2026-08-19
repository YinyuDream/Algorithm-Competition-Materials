#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
char s[maxn];
int main(){
    cin>>n>>(s+1);
    for(int i=1;i<=n;i++)
        if(s[i-1]!='L'&&s[i+1]!='L'&&s[i]!='L')
            s[i]='C';
    cout<<(s+1);
    return 0;
}