#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k;
char s[maxn];
struct node{
    int to,next;
}edge[maxn];
int head[maxn],child[maxn],ans[maxn],pos[maxn],mod[maxn];
int f[maxn][3],g[maxn][3];
void add(int u,int v)
{
    edge[++k].to=v;
    edge[k].next=head[u];
    head[u]=k;
}
void dfs(int u)
{
    if(!child[u]){
        if(s[u]=='W'){
            f[u][1]=f[u][2]=g[u][1]=1;
            g[u][2]=2;
        }
        return ;
    }
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        dfs(v);
    }
    int flag=0;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        int num=f[v][0]+f[v][1]+f[v][2];
        if(num>=2&&flag!=-1){
            if(!pos[u]){
                flag=num;
                pos[u]=v;
            }
        }else if(num==1&&flag!=-1){
            flag=max(flag,1);
        }else{
            flag=-1;
            return ;
        }
    }
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==pos[u])continue;
        if(f[v][0]==1)mod[u]=(mod[u]+0)%3;
        else if(f[v][1]==1)mod[u]=(mod[u]+1)%3;
        else if(f[v][2]==1)mod[u]=(mod[u]+2)%3;
    }
    if(flag>=2){
        if(s[u]=='W'){
            f[u][0]=f[u][1]=f[u][2]=1;
            if(f[pos[u]][0])g[u][(mod[u]+1)%3]=1,g[u][(mod[u]+2)%3]=2;
            if(f[pos[u]][1])g[u][(mod[u]+2)%3]=1,g[u][(mod[u]+0)%3]=2;
            if(f[pos[u]][2])g[u][(mod[u]+0)%3]=1,g[u][(mod[u]+1)%3]=2;
        }else{
            f[u][0]=1;
            if(f[pos[u]][0]&&(0+mod[u]+1)%3==0)g[u][0]=1;
            if(f[pos[u]][0]&&(0+mod[u]+2)%3==0)g[u][0]=2;
            if(f[pos[u]][1]&&(1+mod[u]+1)%3==0)g[u][0]=1;
            if(f[pos[u]][1]&&(1+mod[u]+2)%3==0)g[u][0]=2;
            if(f[pos[u]][2]&&(2+mod[u]+1)%3==0)g[u][0]=1;
            if(f[pos[u]][2]&&(2+mod[u]+2)%3==0)g[u][0]=2;
        }
    }else{
        if(s[u]=='W'){
            f[u][(mod[u]+1)%3]=1;
            g[u][(mod[u]+1)%3]=1;
            f[u][(mod[u]+2)%3]=1;
            g[u][(mod[u]+2)%3]=2;
        }else{
            if((mod[u]+1)%3==0)f[u][0]=1,g[u][0]=1;
            if((mod[u]+2)%3==0)f[u][0]=1,g[u][0]=2;
        }
    }
}
void find_ans(int u,int sum_num)
{
    ans[u]=g[u][sum_num];
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=pos[u]){
            if(f[v][0]==1)find_ans(v,0);
            else if(f[v][1]==1)find_ans(v,1);
            else if(f[v][2]==1)find_ans(v,2);
        }else{
            find_ans(v,((sum_num-g[u][sum_num]-mod[u])%3+3)%3);
        }
    }
}
int main(){
    cin>>n>>(s+1);
    for(int i=2,fa;i<=n;i++){
        cin>>fa;
        add(fa,i);
        child[fa]++;
    }
    dfs(1);
    if(f[1][0]+f[1][1]+f[1][2]==0){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<=2;i++)
        if(f[1][i]){
            find_ans(1,i);
            break;
        }
    for(int i=1;i<=n;i++)
        cout<<ans[i];
    return 0;
}