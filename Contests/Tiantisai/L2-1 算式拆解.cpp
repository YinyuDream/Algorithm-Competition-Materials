#include<bits/stdc++.h>
using namespace std;
bool check(string &s,int l,int r)
{
    for(int i=l;i<=r;i++){
        if(s[i]=='('||s[i]==')'){
            return true;
        }
    }
    return false;
}
void solve(string &s,int l,int r)
{
    l++,r--;
    if(!check(s,l,r)){
        cout<<s.substr(l,r-l+1)<<endl;
        return;
    }
    int stk=0,mid=-1;
    for(int i=l;i<=r;i++){
        if(s[i]=='('){
            stk++;
        }
        if(s[i]==')'){
            stk--;
        }
        if(stk==0&&(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')){
            mid=i;
            break;
        }
    }
    if(!check(s,l,mid)){
        solve(s,mid+1,r);
        cout<<s.substr(l,mid-l+1)<<endl;
        return;
    }
    if(!check(s,mid,r)){
        
        solve(s,l,mid-1);
        cout<<s.substr(mid,r-mid+1)<<endl;
        return;
    }
    solve(s,l,mid-1);
    solve(s,mid+1,r);
    cout<<s[mid]<<endl;
}
int main(){
    string s;
    cin>>s;
    int len=s.size();
    solve(s, 0, len-1);
    return 0;
}