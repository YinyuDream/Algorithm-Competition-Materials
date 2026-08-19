#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10,p=1e9+7;
int T,n,m,k;
struct node{
    int to,next;
}edge[maxn*2];
int head[maxn],size[maxn],val[maxn],root[maxn];
void add(int u,int v)
{
    edge[++k].to=v;
    edge[k].next=head[u];
    head[u]=k;
}
void update(int u,int f,int rt,int num)
{
    root[u]=rt;
    val[u]^=num;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v!=f)update(v,u,rt,num);
    }
}
bool merge(int u,int v,int num)
{
    if(root[u]==root[v]){
        if(val[u]==val[v]&&num==1)return false;
        if(val[u]!=val[v]&&num==0)return false;
        return true;
    }
    if(size[root[u]]>size[root[v]])
        swap(u,v);
    add(u,v);
    add(v,u);
    size[root[v]]+=size[root[u]];
    update(u,v,root[v],num^(val[u]!=val[v]));
    return true;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        size[i]=1,val[i]=0,head[i]=0,root[i]=i;
    for(int i=1;i<=k;i++)
        edge[i].to=edge[i].next=0;
    k=0;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch=getchar();
            while(ch!='0'&&ch!='1')
                ch=getchar();
            a[i][j]=ch-'0';
        }
    }
    if(m%2==1){
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i][m/2+1]==1)
                cnt++;
        if(cnt>=2){
            cout<<0<<endl;
            return ;
        }
    }
    for(int i=1;i<=m/2;i++){
        int cnt=0,posl1=0,posl2=0,posr1=0,posr2=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==1){
                cnt++;
                if(posl1==0)posl1=j;
                else posl2=j;
            }
            if(a[j][m-i+1]==1){
                cnt++;
                if(posr1==0)posr1=j;
                else posr2=j;
            }
        }
        if(cnt>=3){
            cout<<0<<endl;
            return ;
        }else if(cnt<=1){
            continue;
        }else{
            bool flag=true;
            if(posl1&&posr1){
                if(posl1==posr1){
                    continue;
                }else{
                    flag=merge(posl1,posr1,0);
                }
            }else if(posl1&&posl2){
                flag=merge(posl1,posl2,1);
            }else if(posr1&&posr2){
                flag=merge(posr1,posr2,1);
            }
            if(flag==0){
                cout<<0<<endl;
                return ;
            }
        }
    }
    int ans=1;
    for(int i=1;i<=n-k/2;i++)
        ans=ans*2%p;
    cout<<ans<<endl;
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}