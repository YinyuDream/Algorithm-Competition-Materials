#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,k,cnt;
struct node{
    int a,b,c;
}rgb[maxn];
struct point{
    int to,next;
}edge[maxn*maxn];
int head[maxn],in[maxn],real_in[maxn],ans[maxn],rev[maxn];
bool operator==(node i,node j)
{
    return i.a==j.a&&i.b==j.b&&i.c==j.c;
}
bool operator<(node i,node j)
{
    return i.a<j.a&&i.b<j.b&&i.c<j.c;
}
void add(int u,int v)
{
    edge[++k].to=v;
    edge[k].next=head[u];
    head[u]=k;
}
void solve()
{
    queue<int> q;
    for(int i=1;i<=cnt;i++)
        in[i]=real_in[i];
    for(int i=1;i<=cnt;i++)
        if(!in[i])
            q.push(i);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            in[v]--;
            ans[v]=max(ans[v],ans[u]+1);
            if(!in[v]){
                q.push(v);
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        node u={a,b,c};
        int is_in=0;
        for(int i=1;i<=cnt;i++){
            if(rgb[i]==u){
                is_in=i;
                break;
            }
        }
        if(is_in==0){
            rgb[++cnt]=u;
            rev[i]=cnt;
        }else{
            rev[i]=is_in;
        }
    }
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=cnt;j++){
            if(i==j)continue;
            if(rgb[i]<rgb[j]){
                add(i,j);
                real_in[j]++;
            }
        }
    }
    for(int col=0;col<=255;col++){
        memset(ans,0,sizeof ans);
        ans[1]=ans[2]=col;
        solve();
        bool can=true;
        for(int l=1;l<=cnt;l++){
            if(ans[l]>255){
                can=false;
                break;
            }
        }
        if(can==false)
            continue;
        if(ans[1]==ans[2]){
            for(int l=1;l<=n;l++)
                cout<<ans[rev[l]]<<endl;
        return 0;
        }
    }
    cout<<-1;
    return 0;
}