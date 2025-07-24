#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,tot=0;
    cin>>n>>m;
    struct node{
        int to,next;
    };
    vector<node> G(n+1);
    vector<int> head(n+1),col(n+1),book(n+1);
    auto add_edge=[&](int u,int v){
        G[++tot].to=v;
        G[tot].next=head[u];
        head[u]=tot;
    };
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
        add_edge(v,u);
    }
    auto bfs=[&](){
        queue<int>q;
        q.push(1);
        book[1]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=G[i].next){
                int v=G[i].to;
                if(!book[v]){
                    book[v]=1;
                    q.push(v);
                    col[v]=col[u]^1;
                }
            }
        }
    };
    bfs();
    bool can=true;
    for(int i=1;i<=n;i++){
        for(int j=head[i];j;j=G[j].next){
            int v=G[j].to;
            if(col[i]==col[v]){
                can=false;
                break;
            }
        }
    }
    if(can==false){
        cout<<"Alice"<<endl;
    }
    else{
        cout<<"Bob"<<endl;
    }
    cout.flush();
    if(can==false){
        for(int i=1;i<=n;i++){
            cout<<1<<" "<<2<<endl;
            cout.flush();
            int pos,c;
            cin>>pos>>c;
        }
    }else{
        for(int i=1;i<=n;i++)
            col[i]=book[i]=0;
        queue<int>q;
        int cnt=0;
        for(int i=1;i<=n;i++){
            int a,b;
            cin>>a>>b;
            if(q.empty()){
                q.push(1);
                col[1]=a;
                book[1]=1;
                cout<<1<<" "<<a<<endl;
                cout.flush();
            }else{
                int u=q.front();
                bool have=false;
                for(int i=head[u];i;i=G[i].next){
                    if(!book[G[i].to]){
                        have=true;
                        break;
                    }
                }
                if(!have){
                    q.pop();
                    continue;
                }
                bool did=false;
                for(int i=head[u];i;i=G[i].next){
                    int v=G[i].to;
                    if(book[v])continue;
                    did=true;
                    if(col[u]!=a){
                        col[v]=a;
                        q.push(v);
                        book[v]=1;
                        cout<<v<<" "<<a<<endl;
                        cout.flush();
                    }else{
                        col[v]=b;
                        q.push(v);
                        book[v]=1;
                        cout<<v<<" "<<b<<endl;
                        cout.flush();
                    }
                    break;
                }
            }
        }
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