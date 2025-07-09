#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,match[maxn],ans[maxn];
char s[maxn];
stack<int>st;
void work(int l,int r,int nl,int nr)
{
    if(l==r&&nl==nr){
        ans[nl]=l;
        return ;
    }
    for(int i=l;i<=r;i++){
        if(s[i]=='-'||s[i]==')'){
            ans[nl-l+i]=i;
            
        }else{
            work(i+1,match[i],i-l+nl,match[i]-1-l+nl);
            ans[match[i]-l+nl]=i;
            i=match[i];
        }
    }
}
int main(){
    cin>>n>>s+1;
    for(int i=1;i<=n;i++){
        if(s[i]=='('){
            st.push(i);
        }else if(s[i]==')'){
            match[st.top()]=i;
            st.pop();
        }
    }
    work(1,n,1,n);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}