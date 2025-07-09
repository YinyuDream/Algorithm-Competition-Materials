#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k,cnt;
vector<int> a[maxn];
struct node{
    int to,next;
}edge[maxn];
int head[maxn],in[maxn];
void add(int u,int v)
{
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
queue<int> q;
int main(){
    cin>>T;
    while(T--){
        while(!q.empty()) q.pop();
        for(int i=1;i<=k;i++) a[i].clear();
        cin>>n>>k;
        for(int i=1;i<=k;i++){
            for(int j=1,num;j<=n;j++){
                cin>>num;
                a[i].push_back(num);
            }
        }
        for(int i=1;i<=k;i++){
            for(int j=1;j<n-1;j++){
                add(a[i][j],a[i][j+1]);
                in[a[i][j+1]]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=edge[i].next){
                int v=edge[i].to;
                in[v]--;
                if(in[v]==0) q.push(v);
            }
        }
        bool flag=true;
        for(int i=1;i<=n;i++)
            if(in[i]!=0) flag=false;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(int i=1;i<=cnt;i++)
            edge[i].to=edge[i].next=0;
        for(int i=1;i<=n;i++)
            head[i]=in[i]=0;
        cnt=0;
    }
    return 0;
}