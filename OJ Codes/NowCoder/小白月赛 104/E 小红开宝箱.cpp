#include<bits/stdc++.h>
using namespace std;
struct node{
    int to,next,wt;
};
int main(){
    int n;
    cin>>n;
    vector<vector<int>> ord(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int val;
            cin>>val;
            ord[i].push_back(val);
        }
    }
    vector<node> edge(2*n+1);
    vector<int> head(n+1),book(n+1),ans(n+1),in(n+1);
    auto add=[&](int u,int v,int w){
        static int cnt_edge=0;
        edge[++cnt_edge].to=v;
        edge[cnt_edge].next=head[u];
        edge[cnt_edge].wt=w;
        head[u]=cnt_edge;
    };
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(ord[i].size()==1){
            if(book[ord[i][0]]){
                cout<<"kou is angry";
                return 0;
            }
            ans[i]=ord[i][0];
            book[ord[i][0]]=1;
        }else{
            int x=ord[i].front(),y=ord[i].back();
            add(x,y,i);
            add(y,x,i);
            in[x]++,in[y]++;
        }
    }
    auto bfs=[&](int val){
        while(q.size()){
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].next){
                int v=edge[i].to,wt=edge[i].wt;
                if(!book[v]&&!ans[wt]){
                    ans[wt]=val?u:v;
                    book[v]=1;
                    q.push(v);
                }
            }
        }
    };
    bfs(0);
    for(int i=1;i<=n;i++){
        if(in[i]==1&&!book[i]){
            book[i]=1;
            q.push(i);
        }
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        if(book[i]==0){
            q.push(i);
            bfs(1);
        }
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==0){
            cout<<"kou is angry";
            return 0;
        }
    }
    for(int i=1;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<ans[n];
    return 0;
}