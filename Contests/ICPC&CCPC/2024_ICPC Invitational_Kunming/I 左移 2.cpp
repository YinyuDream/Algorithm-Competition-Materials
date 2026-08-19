#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    if(n==1){
        cout<<0<<endl;
        return;
    }
    deque<pair<char,int>> q;
    for(int i=0;i<n;i++){
        if(q.empty()||q.back().first!=s[i]){
            q.push_back({s[i],1});
        }else{
            q.back().second++;
        }
    }
    int cnt=0;
    for(auto [x,y]:q){
        cnt+=y/2;
    }
    int ans=cnt;
    for(int i=1;i<n;i++){
        if(q.front().first==q.back().first){
            cnt-=q.front().second/2;
            cnt-=q.back().second/2;
            q.back().second++;
            q.front().second--;
            if(q.front().second==0){
                q.pop_front();
            }else{
                cnt+=q.front().second/2;
            }
            cnt+=q.back().second/2;
        }else{
            cnt-=q.front().second/2;
            q.push_back({q.front().first,1});
            q.front().second--;
            if(q.front().second==0){
                q.pop_front();
            }else{
                cnt+=q.front().second/2;
            }
            cnt+=q.back().second/2;
        }
        ans=min(ans,cnt);
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