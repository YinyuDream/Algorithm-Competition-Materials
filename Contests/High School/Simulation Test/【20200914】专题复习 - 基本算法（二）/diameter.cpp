#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,cnt_edge,cnt,l,r;
struct node{
    int to,next;
}edge[maxn];
int head[maxn],a[maxn];
int f[maxn],g[maxn];
void add(int u,int v)
{
    edge[++cnt_edge].to=v;
    edge[cnt_edge].next=head[u];
    head[u]=cnt_edge;
}
void pre(int u,int fa)
{
     
    for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa)
        {
            pre(v,u);
            f[u]=max(f[u],f[v]+1);
        }
    }
}
void dfs(int u,int f,int num)
{
    /*for(int i=head[u];i;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=f)dfs(v,u,num);
    }
    int top=0;
    for(int i=head[u];i;i=edge[i].next)
        if(edge[i].to!=f)
            a[++top]=g[edge[i].to]+1;
    sort(a+1,a+top+1);
    for(int i=top;i>=1;i--)
        if(a[i]+a[i-1]<=num)
        {
            cnt+=top-i;
            g[u]=a[i];
            break;
        }*/
    int t=0,lmax=0,rmin=num;
    for(int i=head[u];i;i=edge[i].next)
    {
    	int v=edge[i].to;
    	if(v!=f)
    	{
			dfs(v,u,num);
			
			if(g[v]+1>num)cnt++;
			else if(g[v]+1>num/2){
				t++;
				rmin=min(rmin,g[v]+1);
			}else{
				lmax=max(lmax,g[v]+1);
			}
    	}
    }
    if(t>0){
    	cnt+=t;
    	if(lmax+rmin<=num){
    		cnt--;
    		g[u]=rmin;
    	}else g[u]=lmax;
    	return ;
    }
    g[u]=lmax;
}
bool check(int x)
{
    for(int i=1;i<=n;i++)
        g[i]=f[i];
    cnt=0;
    dfs(1,1,x);
    return cnt<=k;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    pre(1,1);
    l=1,r=n-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}
