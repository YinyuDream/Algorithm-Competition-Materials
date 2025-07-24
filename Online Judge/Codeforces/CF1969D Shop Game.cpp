#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
struct node{
    int a,b;
}c[maxn];
bool operator<(node u,node v){
    return u.b>v.b;
}
priority_queue<int> q;
int main(){
    cin>>T;
    while(T--){
        while(q.size())
            q.pop();
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>c[i].a;
        for(int i=1;i<=n;i++)
            cin>>c[i].b;
        if(k==0){
            ll ans=0;
            for(int i=1;i<=n;i++)
                ans+=max(0,c[i].b-c[i].a);
            cout<<ans<<endl;
            continue;
        }
        sort(c+1,c+n+1);
        ll sum_a=0,sum_b=0;
        for(int i=1;i<=k;i++){
            q.push(c[i].a);
            sum_a+=c[i].a;
        }
        for(int i=k+1;i<=n;i++)
            if(c[i].b>=c[i].a)
                sum_b+=c[i].b-c[i].a;
        ll ans=max(0ll,sum_b-sum_a);
        for(int i=k+1;i<=n;i++){
            if(c[i].a<q.top()){
                sum_a+=c[i].a-q.top();
                q.pop();
                q.push(c[i].a);
            }
            if(c[i].b>=c[i].a)
                sum_b-=c[i].b-c[i].a;
            ans=max(ans,sum_b-sum_a);
        }
        cout<<ans<<endl;
    }
    return 0;
}