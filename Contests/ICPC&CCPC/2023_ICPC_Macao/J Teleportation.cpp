#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n,ed;
    cin>>n>>ed;
    vector<int> dis(n),a(n);
    vector<vector<int>> book(n,vector<int>(2));
    for(int i=0;i<n;i++)
        cin>>a[i];
    queue<pii> q;
    q.push({0,0});
    book[0][0]=1;
    while(!q.empty()){
        pii _=q.front();
        int u=_.first,step=_.second;
        q.pop();
        if(!book[(u+1)%n][step]&&step){
            dis[(u+1)%n]=dis[u]+1;
            book[(u+1)%n][step]=1;
            q.push({(u+1)%n,step});
        }
        if(!book[(u+a[u])%n][1]){
            dis[(u+a[u])%n]=dis[u]+1;
            book[(u+a[u])%n][1]=1;
            q.push({(u+a[u])%n,1});
        }
    }
    cout<<dis[ed];    
    return 0;
}
