#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,next;
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<node> edge(m+1);
    vector<int> head(n+1);
    auto add=[&](int u,int v){
        static int cnt=0;
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    vector<int> book(n+1),dep(n+1,1e9);
    auto bfs=[&](){
        queue<int> q;
        q.push(1);
        book[1]=1;
        dep[1]=0;
        while(q.size()){
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].next){
                int v=edge[i].to;
                if(!book[v]){
                    book[v]=1;
                    dep[v]=dep[u]+1;
                    q.push(v);
                }
            }
        }
    };
    bfs();
    int ans=1e9;
    for(int i=2;i<=n;i++){
        for(int j=head[i];j;j=edge[j].next){
            int v=edge[j].to;
            if(v==1){
                ans=min(ans,dep[i]+1);
            }
        }
    }
    cout<<(ans==1e9?-1:ans)<<endl;
    return 0;
}