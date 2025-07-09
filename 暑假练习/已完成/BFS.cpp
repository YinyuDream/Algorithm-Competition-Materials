#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m;
int mapp[maxn][maxn],book[maxn];
queue<int>q;
int main(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        mapp[u][v]=mapp[v][u]=1;
    }
    q.push(1);
    book[1]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int i=1;i<=n;i++){
            if(mapp[u][i]&&!book[i]){
                book[i]=1;
                q.push(i);
            }
        }
    }
    return 0;
}