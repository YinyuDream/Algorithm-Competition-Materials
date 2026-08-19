#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<queue>
using namespace std;
#define INF 1000000000
#define MAXN 1010
#define mod ((1<<31)-1)
struct node1{long long y,next,v;}e[MAXN*MAXN];
struct node2{long long id,v;}dis[MAXN];
long long n,m,len,ans=1,Link[MAXN],vis[MAXN],q[MAXN],map[MAXN][MAXN];
inline long long read()
{
    long long x=0,f=1;  char ch=getchar();
    while(!isdigit(ch))  {if(ch=='-')  f=-1;  ch=getchar();}
    while(isdigit(ch))  {x=x*10+ch-'0';  ch=getchar();}
    return x*f;
}
void insert(long long x,long long y,long long v) {e[++len].next=Link[x];Link[x]=len;e[len].y=y;e[len].v=v;}
bool cmp(node2 a,node2 b)  {return a.v<b.v;}
void spfa()
{
    for(long long i=1;i<=n;i++)  dis[i].id=i,dis[i].v=INF;
    long long head=0,tail=1;  
    q[1]=1;  vis[1]=1;  dis[1].v=0;
    while(++head<=tail)
    {
        long long x=q[head];
        for(long long i=Link[x];i;i=e[i].next)
        {
            if(dis[x].v+e[i].v<dis[e[i].y].v)
            {
                dis[e[i].y].v=dis[x].v+e[i].v;
                if(!vis[e[i].y])
                {
                    q[++tail]=e[i].y;
                    vis[e[i].y]=1;
                }
            }
        }
        vis[x]=0;
    }
}
int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    n=read();  m=read();
    memset(map,10,sizeof(map));
    for(long long i=1;i<=m;i++)
    {
        long long x=read(),y=read(),v=read();
        insert(x,y,v);  insert(y,x,v);
        map[x][y]=min(map[x][y],v);
        map[y][x]=map[x][y];
    }
    spfa();
    sort(dis+1,dis+n+1,cmp);
    for(long long i=2;i<=n;i++)
    {
        long long temp=0;
        for(long long j=1;j<i;j++)
        {
            long long x=dis[i].id,y=dis[j].id;
            if(dis[i].v==dis[j].v+map[x][y])  temp++;
        }
        ans=ans*temp%mod;
    }
    printf("%d\n",ans);
    return 0;
}
