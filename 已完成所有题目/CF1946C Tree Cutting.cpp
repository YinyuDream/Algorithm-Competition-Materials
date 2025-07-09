#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int cnt,k;
struct node{
    int to,next;
}edge[maxn];
int head[maxn];
int T,n;
vector<int>a[maxn];
void add(int u,int v){
    edge[++cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt;
}
int solve(int u,int f,int &num,int x)
{
    if(head[u]==0)return 1;
    for(int i=head[u];i;i=edge[i].next){
        int v=edge[i].to;
        if(v==f)continue;
        a[u].push_back(solve(v,u,num,x));
    }
    int sum=0;
    for(auto i:a[u]){
        if(i>=x)num++;
        else sum+=i;
    }
    return sum+1;
}
bool check(int x)
{
    for(int i=1;i<=n;i++)
        a[i].clear();
    int num=0;
    int big=solve(1,1,num,x);
    if(num>=k&&big>=x)return true;
    if(num>k&&big<x)return true;
    return false;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            head[i]=0;
        for(int i=1;i<=n*2;i++)
            edge[i].to=edge[i].next=0;
        cnt=0;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v);
            add(v,u);
        }
        int l=1,r=n;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        cout<<l-1<<endl;
    }
    return 0;
}