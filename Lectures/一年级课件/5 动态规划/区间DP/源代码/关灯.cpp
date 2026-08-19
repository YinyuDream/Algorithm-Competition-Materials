#include<bits/stdc++.h>
using namespace std;

int n,v;
int dis[1010],w[1010];

int f[1010][1010][2];
int cost[1010][1010]; 

inline void read (int &x)
{
    x=0;int f=1;char s=getchar();
    for(;s<'0'||s>'9';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=(x<<3)+(x<<1)+s-48;
    x*=f;
}

void init()
{
    read(n);read(v);
    memset(dis,0,sizeof(dis));
    memset(w,0,sizeof(w));
    memset(cost,0,sizeof(cost));
    int x;
    for(int i=1;i<=n;++i){
        read(dis[i]);read(x);
        w[i]=w[i-1]+x;
    }
    for(int i=1;i<=n;++i) 
        for(int j=i;j<=n;++j)
		cost[i][j]=cost[j][i]=w[n]-w[j]+w[i-1];
}

void work()
{
    memset(f,10,sizeof(f));
    f[v][v][0]=f[v][v][1]=0;
    for(int k=2;k<=n;++k)
        for(int i=1;i<=n-k+1;++i)
        {
            int j=i+k-1;
            f[i][j][0]=min(f[i+1][j][0]+cost[i+1][j]*(dis[i+1]-dis[i]),f[i+1][j][1]+cost[i+1][j]*(dis[j]-dis[i]));
            f[i][j][1]=min(f[i][j-1][0]+cost[i][j-1]*(dis[j]-dis[i]),f[i][j-1][1]+cost[i][j-1]*(dis[j]-dis[j-1]));
        }
    printf("%d",min(f[1][n][0],f[1][n][1]));
}  

int main()
{
    init();
    work();
    return 0;
}

