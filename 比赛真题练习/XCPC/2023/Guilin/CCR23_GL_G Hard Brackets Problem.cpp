#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
char s[maxn];
void work()
{
    int pos=0,mn=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='(')
            pos++;
        else pos--;
        mn=min(mn,pos);
    }
    if(pos>mn)printf("%s\n","impossible");
    else printf("%s\n",s+1);
}
int main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        work();
    }
    return 0;
}