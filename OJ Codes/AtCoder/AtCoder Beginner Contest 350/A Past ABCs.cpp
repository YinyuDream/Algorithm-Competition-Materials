#include<bits/stdc++.h>
using namespace std;
char s[7];
int main(){
    cin>>s;
    int num=(s[3]-'0')*100+(s[4]-'0')*10+(s[5]-'0');
    if(num<=349&&num!=316&&num)cout<<"Yes";
    else cout<<"No";
    return 0;
}