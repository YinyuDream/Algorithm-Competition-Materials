#include<bits/stdc++.h>
using namespace std;
int work_array(string &s)
{
    int num=(s[0]=='l'?8:4),tot=0;
    for(auto i=s.begin();i!=s.end();i++){
        if(*i=='['){
            auto pos=i;
            for(auto j=i+1;j<=s.end();j++){
                if(*j==']'){
                    pos=j;
                    break;
                }
            }
            int ans=0;
            for(auto j=i+1;j<pos;j++)
                ans=ans*10+*j-'0';
            ans*=num;
            tot+=ans;
        }
    }
    return tot;
}
int work_var(string &s)
{
    int num=0;
    if(s[0]=='i')num=4;
    else if(s[0]=='l')num=8;
    else num=1;
    if(num==4||num==8){
        int cnt=0;
        for(auto i:s){
            if(i==',')
                cnt++;
        }
        return (cnt+1)*num;
    }else{
        int cnt=0;
        for(auto i=s.begin();i!=s.end();i++){
            if(*i==34){
                for(auto j=i+1;j!=s.end();j++)
                    if(*j==34){
                        cnt+=j-i-1;
                        i=j;
                        break;
                    }
            }
        }
        return cnt;
    }
}
int work()
{
    string s;
    getline(cin,s);
    while(s.empty())getline(cin,s);
    bool flag=true;
    for(auto i:s){
        if(i=='['){
            flag=false;
            break;
        }
    }
    if(!flag)return work_array(s);
    else return work_var(s);
}
int main(){
    int T,tot=0;
    cin>>T;
    while(T--){
        tot+=work();
    }
    int GB=0,MB=0,KB=0,B=0;
    B=tot%1024,tot/=1024;
    KB=tot%1024,tot/=1024;
    MB=tot%1024,tot/=1024;
    GB=tot%1024,tot/=1024;
    if(GB)cout<<GB<<"GB";
    if(MB)cout<<MB<<"MB";
    if(KB)cout<<KB<<"KB";
    if(B)cout<<B<<"B";
    return 0;
}