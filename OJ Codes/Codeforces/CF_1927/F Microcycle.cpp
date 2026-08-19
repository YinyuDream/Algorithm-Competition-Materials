#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,m,cnt,k,num1,num2;
struct edge{
	int x,y,val,used;
}e[maxn];
struct node{
    int to,next,wt;
}e2[maxn];
int head[maxn],ans1[maxn],ans2[maxn];
bool cmp(edge a,edge b)
{
	return a.val>b.val;
}
int fa[maxn];
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void add(int u,int v,int w)
{
	e2[++k].to=v;
	e2[k].next=head[u];
    e2[k].wt=w;
	head[u]=k;
}
int book[maxn],deep[maxn],fa2[maxn][20];
void dfs(int x)
{
	book[x]=true;
	for(int i=1;(1<<i)<=deep[x];i++)
		fa2[x][i]=fa2[fa2[x][i-1]][i-1];
	for(int i=head[x];i;i=e2[i].next)
	{
		if(!book[e2[i].to])
		{
			fa2[e2[i].to][0]=x;
			deep[e2[i].to]=deep[x]+1;
			dfs(e2[i].to);
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
			x=fa2[x][i];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(fa2[x][i]!=fa2[y][i])
			x=fa2[x][i],y=fa2[y][i];
	return fa2[x][0];
}
int main(){
	cin>>T;
	while(T--){
        cnt=k=num1=num2=0;
		cin>>n>>m;
        for(int i=1;i<=n;i++){
            fa[i]=i,head[i]=0,book[i]=0,deep[i]=0;
            for(int j=0;j<=19;j++){
                fa2[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>e[i].x>>e[i].y>>e[i].val;
            e[i].used=0;
            e2[i*2-1].to=e2[i*2-1].next=e2[i*2-1].wt=0;
            e2[i*2].to=e2[i*2].next=e2[i*2].wt=0;
        }
        sort(e+1,e+m+1,cmp);
        for(int i=1;i<=m;i++){
            int fx=find(e[i].x),fy=find(e[i].y);
            if(fx!=fy)fa[fx]=fy,cnt++,add(e[i].x,e[i].y,e[i].val),add(e[i].y,e[i].x,e[i].val),e[i].used=1;
            if(cnt==n-1)break;
        }
        for(int i=1;i<=n;i++){
            if(!book[i]){
                fa2[i][0]=i;
	            dfs(i);
            }
        }
        int pos=m;
        for(int i=m;i;i--)
            if(!e[i].used){
                pos=i;
                break;
            }
        int lca=LCA(e[pos].x,e[pos].y);
        while(e[pos].x!=lca){
            ans1[++num1]=e[pos].x;
            e[pos].x=fa2[e[pos].x][0];
        }
        while(e[pos].y!=lca){
            ans2[++num2]=e[pos].y;
            e[pos].y=fa2[e[pos].y][0];
        }
        cout<<e[pos].val<<" "<<num1+num2+1<<endl;
        for(int i=1;i<=num1;i++)
            cout<<ans1[i]<<" ";
        cout<<lca<<" ";
        for(int i=num2;i;i--)
            cout<<ans2[i]<<" ";
        cout<<endl;
        
	}
	return 0;
}