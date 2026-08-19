#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    const string a="fc",b="tb";
    vector<int> nxt(n+1),pre(n+1);
    for(int i=1;i<=n;i++){
        nxt[i]=i+1;
        pre[i]=i-1;
    }
    set<int> pos;
    for(int i=1;i<n;i++){
        if(s.substr(i,2)==a||s.substr(i,2)==b){
            pos.insert(i);
        }
    }
    int ans=n;
    while(pos.size()){
        int p=*pos.begin();
        pos.erase(p);
        int l=p,r=nxt[p];
        ans-=2;
        nxt[pre[l]]=nxt[r];
        pre[nxt[r]]=pre[l];
        if(l==0||r==n+1)continue;
        string tmp;
        tmp.push_back(s[pre[l]]);
        tmp.push_back(s[nxt[r]]);
        if(tmp==a||tmp==b){
            pos.insert(pre[l]);
        }
    }
    cout<<ans<<endl;
    return 0;
}