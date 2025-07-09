#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    s=" "+s;
    t=" "+t;
    vector<set<int>> st(n+1);
    vector<int> c(n+1);
    auto add=[&](int x,int val){
        for(int i=x;i<=n;i+=i&-i){
            c[i]+=val;
        }
    };
    auto query=[&](int x){
        int res=0;
        for(int i=x;i>0;i-=i&-i){
            res+=c[i];
        }
        return res&1;
    };
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        st[l].insert(r);
    }
    for(int i=1;i<=n;i++){
        if(st[i].empty()){
            continue;
        }
        if(st[i].size()>1){
            vector<int> tmp(st[i].begin(),st[i].end());
            st[i].clear();
            st[i].insert(tmp[0]);
            int sz=tmp.size();
            for(int j=0;j<sz-1;j++){
                st[tmp[j]+1].insert(tmp[j+1]);
            }
            
        }
        int now=i+1,diff=0;
        while(now<=n&&st[now].empty()){
            now++;
        }
        for(int j=i;j<now;j++){
            if(s[j]!=t[j]){
                diff=j;
                break;
            }
        }
        int r=*st[i].begin();
        if(diff){
            int q=query(diff);
            if((q==0&&s[diff]=='0')||(q==1&&s[diff]=='1')){
                add(i,1);
                add(r+1,-1);
            }
            st[i].clear();
            continue;
        }
        if(now>n){
            break;
        }
        int nowr=*st[now].begin();
        st[i].clear();
        if(r<now){
            continue;
        }
        if(r==nowr){
            continue;
        }else if(r<nowr){
            st[now].insert(r);
            st[r+1].insert(nowr);
        }else{
            st[nowr+1].insert(r);
        }
    }
    for(int i=1;i<=n;i++){
        int q=query(i);
        if(q==1){
            swap(s[i],t[i]);
        }
    }
    s.erase(0,1);
    cout<<s;
    return 0;
}