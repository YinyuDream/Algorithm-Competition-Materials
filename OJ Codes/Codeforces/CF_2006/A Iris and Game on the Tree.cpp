#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int to,next;
};
void solve(){
    int n,cnt=0,tot=0;
    cin>>n;
    vector<node> edge(2*n+1);
    vector<int> head(n+1,0);
    auto add_edge=[&](int u,int v){
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    string s;
    cin>>s;
    s=" "+s;
    vector<char> leaf;
    int num=0,cnt_0=0,cnt_1=0;
    function<void(int,int)> dfs=[&](int u,int fa){
        bool is_leaf=true;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v==fa)
                continue;
            is_leaf=false;
            dfs(v,u);
        }
        if(is_leaf){
            if(s[u]!='?'){
                cnt_0+=(s[u]=='0');
                cnt_1+=(s[u]=='1');
                leaf.push_back(s[u]);
            }else{
                tot++;
            }
        }else{
            if(u!=1&&s[u]=='?'){
                num++;
            }
        }
    };
    dfs(1,0);
    auto work=[&](int rt,int op){
        int ans=0;
        for(auto &c:leaf){
            ans+=(rt!=(c-'0'));
        }
        for(int i=1;i<=tot;i++){
            if((i+op)&1){
                ans++;
            }
        }
        return ans;
    };
    num%=2;
    if(s[1]!='?'){
        cout<<work(s[1]-'0',0)<<endl;
    }else{
        int ans=max(work(0,1),work(1,1));
        if(num==1){
            ans=max(ans,work(cnt_0>cnt_1?0:1,0));
        }
        if(cnt_0>cnt_1){
            cnt_0++;
            leaf.push_back('0');
        }else{
            cnt_1++;
            leaf.push_back('1');
        }
        tot--;
        cout<<max(ans,work(cnt_0>cnt_1?0:1,0))<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}