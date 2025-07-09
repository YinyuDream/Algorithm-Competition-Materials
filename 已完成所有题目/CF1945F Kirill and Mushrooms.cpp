#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],p[maxn];
priority_queue<int,vector<int>,greater<int>> q_up;
priority_queue<int> q_down;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>p[i];
        int k=(n+1)/2;
        while (q_up.size()) q_up.pop();
        while (q_down.size()) q_down.pop();
        for(int i=k;i<=n;i++)
            q_up.push(a[p[i]]);
        while(q_up.size()>k){
            q_down.push(q_up.top());
            q_up.pop();
        }
        ll ans=1ll*k*q_up.top(),num=k;
        for(int i=k-1;i;i--){
            if(a[p[i]]>=q_up.top()) q_up.push(a[p[i]]);
            else q_down.push(a[p[i]]);
            while(q_up.size()>i){
                q_down.push(q_up.top());
                q_up.pop();
            }
            if(ans<=1ll*i*q_up.top()){
                num=i;
                ans=1ll*i*q_up.top();
            }

        }
        cout<<ans<<" "<<num<<endl;
    }
    return 0;
}