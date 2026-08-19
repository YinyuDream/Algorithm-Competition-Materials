#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll p=998244353;
int T,n,cnt;
struct node{
    int to,next;
}edge[maxn];
int head[maxn];
ll f[maxn][3];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;

}
void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
void solve(int u,int fa)
{
    ll sum_1=1,sum_2=1,sum_3=1;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=fa){
            solve(v,u);
            sum_1*=(f[v][0]+f[v][2]);
            sum_2*=(f[v][0]+f[v][1]);
            sum_3*=f[v][0];
            sum_1%=p,sum_2%=p,sum_3%=p;
        }
    }

    f[u][0]=sum_2,f[u][1]=(sum_1-sum_3)%p,f[u][2]=sum_1;
    f[u][1]=(f[u][1]+p)%p;
}
int main(){
    T=read();
    while(T--){
        n=read();
        for(int i=1;i<n;i++){
            int u,v;
            u=read(),v=read();
            add(u,v);
            add(v,u);
        }
        solve(1,1);
        cout<<((f[1][0]+f[1][1])%p+p)%p<<endl;
        for(int i=1;i<=n;i++){
            head[i]=0;
            f[i][0]=f[i][1]=f[i][2]=0;
        }
        for(int i=1;i<=n*2;i++){
            edge[i].to=edge[i].next=0;
        }
        cnt=0;
    }
    return 0;
}