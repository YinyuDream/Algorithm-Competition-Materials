#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int to,next;
};
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<node> edge(n*2+1);
    vector<int> head(n+1);
    auto add=[&](int u,int v){
        static int cnt=0;
        edge[++cnt].to=v;
        edge[cnt].next=head[u];
        head[u]=cnt;
    };
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    vector<vector<array<ll,2>>> dp(n+1,vector<array<ll,2>>(10,{0,0}));
    auto dfs=[&](auto &&self,int u,int f)->void{
        dp[u][a[u]][0]=1;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(v!=f){
                self(self,v,u);
                for(int j=a[u];j<=9;j++){
                    dp[u][j][0]+=dp[v][j-a[u]][0];
                }
                for(int j=0;j<=9;j++){
                    dp[u][j][1]+=dp[v][j][0]+dp[v][j][1];
                }
            }
        }
        for(int j=0;j<=9;j++){
            ll sum=0;
            for(int k=0;k<=j-a[u]-k;k++){//k+(j-a[u]-k)
                ll tot=0,sum_1=0,sum_2=0;
                for(int i=head[u];i;i=edge[i].next){
                    int v=edge[i].to;
                    if(v!=f){
                        sum_1+=dp[v][k][0];
                        sum_2+=dp[v][j-a[u]-k][0];
                        tot+=dp[v][k][0]*dp[v][j-a[u]-k][0];
                    }
                }
                sum+=(sum_1*sum_2-tot)/(1+(k==j-a[u]-k));
            }
            dp[u][j][1]+=sum;
        }
    };
    dfs(dfs,1,0);
    ll ans=0;
    for(int i=0;i<=9;i++)
        ans+=dp[1][i][0]+dp[1][i][1];
    cout<<ans-n<<endl;
    return 0;
}