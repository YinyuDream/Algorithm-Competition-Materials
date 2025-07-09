#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,ans;
ll lim,sum;
struct node{
    ll a,b;
}t[maxn];
bool operator<(node a,node b)
{
    return a.b<b.b;
}
priority_queue<ll>q;
int main(){
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>lim;
        for(int i=1;i<=n;i++)
            cin>>t[i].a>>t[i].b;
        sort(t+1,t+n+1);
        for(int i=1;i<=n;i++){
            sum=0;
            while(q.size())
                q.pop();
            for(int j=i;j<=n;j++){
                q.push(t[j].a);
                sum+=t[j].a;
                while(!q.empty()&&t[j].b-t[i].b+sum>lim){
                    sum-=q.top();
                    q.pop();
                }
                if(t[j].b-t[i].b+sum<=lim)
                    ans=max(ans,(int)q.size());
                
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}