#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,k,mx=0;
    cin>>n>>m>>k;
    vector<int> v(1e6+1),t;
    for(int i=1;i<=n;i++){
        int d,a;
        cin>>d>>a;
        v[d]=a;
        t.push_back(d);
        t.push_back(d+k);
    }
    deque<pair<int,int>> q;//size,day
    q.push_back({0,0});
    int ans=0,tot=0;
    for(int i=0;i<t.size();i++){
        while(q.size()&&q.front().second+k-1<t[i]-1){
            tot-=q.front().first;
            q.pop_front();
        }
        if(v[i]){
            q.push_back({v[i],i});
            tot+=v[i];
        }
        int lst=q.front().second;
        int len=t[i]-lst;
        ans+=min(len,tot/m);
        lst=t[i];
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}