#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;i++){
        cin>>v[i].first>>v[i].second;
        v[i].first--;
        v[i].second--;
    }
    deque<int> q;
    q.push_back(1);
    for(int i=1;i<n;i++){
        q.push_back(0);
    }
    int head=0;
    for(int i=0;i<k;i++){
        deque<pair<int,int>> now;
        for(auto [x,y]:v)
            now.push_back({y,q[x]});
        q.push_front(q.back());
        q.pop_back();
        for(auto [x,y]:now){
            q[x]+=y;
            q[x]%=p;
        }
    }
    int ans=0;
    for(auto x:q){
        ans+=x;
        ans%=p;
    }
    cout<<ans<<endl;
    return 0;
}