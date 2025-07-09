#include<bits/stdc++.h>
using namespace std;
int T;
int relation(char u,char v)
{
    if(u==v)return 0;
    if(u=='S'&&v=='R')return 1;
    if(u=='P'&&v=='S')return 1;
    if(u=='R'&&v=='P')return 1;
    return -1;
}
int find_max(char u,char v)
{
    if(relation(u,v)==1)return v;
    else return u;
}
char nxt[128];
void work()
{
    string s;
    cin>>s;
    if(s.length()==1){
        cout<<s<<endl;
        return;
    }
    int len=1;
    for(int i=1;i<s.length();i++){
        if(relation(s[i-1],s[i])==1)
            len=max(len-1,1);
        if(relation(s[i-1],s[i])==-1)
            len++;
    }
    char ch=s.back();
    for(int i=1;i<len;i++){
        ch=nxt[ch];
    }
    cout<<ch<<endl;
}
int main(){
    nxt['R']='P';
    nxt['P']='S';
    nxt['S']='R';
    cin>>T;
    while(T--){
        work();
    }
    return 0;
}