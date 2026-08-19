#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,k,mx=0;
    cin>>n>>m>>k;
    vector<int> v(1e6+1);
    for(int i=1;i<=n;i++){
        int d,a;
        cin>>d>>a;
        v[d]=a;
        mx=max(mx,d);
    }
    deque<pair<int,int>> q;//size,day
    int ans=0;
    for(int i=1;i<=mx+k-1;i++){
        while(q.size()&&q.front().second+k-1<i){
            q.pop_front();
        }
        if(v[i]){
            q.push_back({v[i],i});
        }
        int val=m;
        while(q.size()&&val){
            int t=q.back().first;
            if(val>=t){
                val-=t;
                q.pop_back();
            }else{
                q.back().first-=val;
                val=0;
            }
        }
        if(val==0){
            ans++;
        }
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