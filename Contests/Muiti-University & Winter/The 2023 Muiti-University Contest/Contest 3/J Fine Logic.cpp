#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,m,cnt_edge,ans=1;
struct node{
    int fr,to,next;
}edge[maxn];
int head[maxn],fa[maxn][20],deep[maxn],in[maxn];
bool book[maxn],book_edge[maxn];
void add(int u,int v)
{
    edge[++cnt_edge].to=v;
    edge[cnt_edge].fr=u;
    edge[cnt_edge].next=head[u];
    head[u]=cnt_edge;
}
void dfs(int x)
{
	book[x]=true;
	for(int i=1;(1<<i)<=deep[x];i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=edge[i].next)
	{
		if(!book[edge[i].to])
		{
			fa[edge[i].to][0]=x;
			deep[edge[i].to]=deep[x]+1;
            book_edge[i]=true;
			dfs(edge[i].to);
		}
	}
}
queue<int>q;
void dp(int opt)
{
    q.push(0);
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=edge[i].next){
            if(opt==0){
                if(book_edge[i]){
                    int v=edge[i].to;
                    in[v]--;
                    if(in[v]==0){
                        cout<<v<<" ";
                        q.push(v);
                    }
                }
            }else{
                if(book_edge[i]==0||edge[i].fr==0){
                    int v=edge[i].to;
                    in[v]--;
                    if(in[v]==0){
                        cout<<v<<" ";
                        q.push(v);
                    }
                }
            }
        }
    }
}
int LCA(int x,int y)
{
	if(deep[x]<deep[y])
		swap(x,y);
	int h=deep[x]-deep[y];
	for(int i=0;(1<<i)<=h;i++)
		if((1<<i)&h)
			x=fa[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main(){
    cin>>n>>m;
    for(int i=1,u,v;i<=m;i++){
        cin>>u>>v;
        add(u,v);
    }
    for(int i=1;i<=n;i++)
        add(0,i);
    dfs(0);
    for(int i=1;i<=m+n;i++){
        if(!book_edge[i]){
            if(edge[i].to==LCA(edge[i].fr,edge[i].to)){
                ans=2;
            }else{
                book_edge[i]=true;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n+m;i++)
        if(book_edge[i])
            in[edge[i].to]++;
    dp(0);
    if(ans==2){
        for(int i=1;i<=n+m;i++)
            if(book_edge[i]==0||edge[i].fr==0)
                in[edge[i].to]++;
        cout<<endl;
        dp(1);
    }
    return 0;
}