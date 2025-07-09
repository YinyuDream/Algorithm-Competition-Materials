#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const ll mod=998244353;
int n,m,x,y;
int a[maxn][maxn],mn[maxn][maxn],mx[maxn][maxn];
ll ans=0;
deque<pair<int,int> >q,p;
int main(){
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=m;i++){
        while(q.size())
            q.pop_front();
        for(int j=1;j<=x;j++){
            while(q.size()&&a[j][i]>=q.back().first)
                q.pop_back();
            q.push_back(make_pair(a[j][i],j));
        }
        for(int j=1;j+x-1<=n;j++){
            mx[j][i]=q.front().first;
            if(q.size()&&j+x-q.front().second+1>x)
                q.pop_front();
            while(q.size()&&a[j+x][i]>=q.back().first)
                q.pop_back();
            q.push_back(make_pair(a[j+x][i],j+x));
        }
    }
    for(int i=1;i<=m;i++){
        while(q.size())
            q.pop_front();
        for(int j=1;j<=x;j++){
            while(q.size()&&a[j][i]<=q.back().first)
                q.pop_back();
            q.push_back(make_pair(a[j][i],j));
        }
        for(int j=1;j+x-1<=n;j++){
            mn[j][i]=q.front().first;
            if(q.size()&&j+x-q.front().second+1>x)
                q.pop_front();
            while(q.size()&&a[j+x][i]<=q.back().first)
                q.pop_back();
            q.push_back(make_pair(a[j+x][i],j+x));
        }
    }
    for(int i=1;i+x-1<=n;i++){
        while(q.size())
            q.pop_front();
        while(p.size())
            p.pop_front();
        for(int j=1;j<=y;j++){
            while(p.size()&&mn[i][j]<=p.back().first)
                p.pop_back();
            p.push_back(make_pair(mn[i][j],j));
            while(q.size()&&mx[i][j]>=q.back().first)
                q.pop_back();
            q.push_back(make_pair(mx[i][j],j));
        }
        ans=(ans+1ll*p.front().first*q.front().first)%mod;
        for(int j=y+1;j<=m;j++){
            if(p.size()&&j-p.front().second+1>y)
                p.pop_front();
            while(p.size()&&mn[i][j]<=p.back().first)
                p.pop_back();
            p.push_back(make_pair(mn[i][j],j));
            if(q.size()&&j-q.front().second+1>y)
                q.pop_front();
            while(q.size()&&mx[i][j]>=q.back().first)
                q.pop_back();
            q.push_back(make_pair(mx[i][j],j));
            ans=(ans+1ll*p.front().first*q.front().first)%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}