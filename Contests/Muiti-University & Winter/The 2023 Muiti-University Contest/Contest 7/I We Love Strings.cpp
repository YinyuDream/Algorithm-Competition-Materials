#include<bits/stdc++.h>
using namespace std;
const int maxn=410,p=998244353;
int n,ans,mx;
vector<string>v[maxn];
bool check(string s,string t)
{
    int len=s.length();
    for(int i=0;i<len;i++)
        if(t[i]!='?'&&t[i]!=s[i])
            return false;
    return true;
}
int work_1(int pos,int tot,string now)
{
    if(pos==tot+1){
        for(auto i:v[tot])
            if(check(now,i))
                return 1;
        return 0;
    }
    return (work_1(pos+1,tot,now+"0")+work_1(pos+1,tot,now+"1"))%p;
}
int num[maxn],top;
int solve(int len)
{
    if(top==0)return 0;
    string s;
    for(int i=0;i<len;i++){
        char ch='?';
        for(int j=1;j<=top;j++){
            if(v[len][num[j]][i]=='0'){
                if(ch=='1')
                    return 0;
                else ch='0';
            }
            if(v[len][num[j]][i]=='1'){
                if(ch=='0')return 0;
                else ch='1';
            }
        }
        s.push_back(ch);
    }
    int ans=1;
    for(auto i:s)
        if(i=='?')
           ans=ans*2%p;
    return ans;
}
void work_2(int len,int pos,int tot)
{
    if(pos==tot+1){
        ans=(ans+((top&1)*2-1)*solve(len))%p;
        return ;
    }
    work_2(len,pos+1,tot);
    num[++top]=pos;
    work_2(len,pos+1,tot);
    top--;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        v[s.length()].push_back(s);
        if(mx<s.length())
            mx=s.length();
    }
    for(int i=1;i<=mx;i++){
        if(v[i].size()){
            if(i<=sqrt(n)){
                ans=(ans+work_1(1,i,""))%p;
            }else{
                work_2(i,0,v[i].size()-1);
            }
        }
    }
    cout<<(ans+p)%p;
    return 0;
}