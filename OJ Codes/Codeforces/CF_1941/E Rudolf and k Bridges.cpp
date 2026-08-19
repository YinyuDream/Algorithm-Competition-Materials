#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=2e5+10,maxn=1e2+10;
int T,n,m,k,d;
int a[maxn][maxm];
ll f[maxm],sum[maxn];
deque<pair<int,ll> >q;//位置，大小
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k>>d;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++){
            f[1]=1;
            for(int i=2;i<=m;i++)
                f[i]=0;
            while(q.size())
                q.pop_front();
            q.push_back(make_pair(1,1));
            for(int j=2;j<m;j++){
                while(q.size()&&j-q.front().first-1>d)
                    q.pop_front();
                f[j]=1+a[i][j]+q.front().second;
                while(q.size()&&q.back().second>=f[j])
                    q.pop_back();
                q.push_back(make_pair(j,f[j]));
            }
            while(q.size()>1&&m-q.front().first-1>d)
                q.pop_front();
            f[m]=1+q.front().second;
            sum[i]=f[m];
        }
        for(int i=2;i<=n;i++)
            sum[i]+=sum[i-1];
        ll ans=1e18;
        for(int i=1;i<=n-k+1;i++)
            ans=min(ans,sum[i+k-1]-sum[i-1]);
        cout<<ans<<endl;
    }
    return 0;
}