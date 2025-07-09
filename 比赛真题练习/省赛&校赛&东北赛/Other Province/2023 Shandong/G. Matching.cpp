#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];
struct node{
    ll a,b;
}t[maxn];
bool operator<(node u,node v){
    if(u.b!=v.b) return u.b<v.b;
    return u.a<v.a;
}
ll work(int l,int r)
{
    ll tot=0;
    for(int i=r-1;i>=l;i-=2){
        ll sum=t[i].a+t[i+1].a;
        if(sum<0)break;
        tot+=sum;
    }
    return tot;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>t[i].a;
            t[i].b=t[i].a-i;
        }
        sort(t+1,t+n+1);
        int l=1;ll ans=0;
        for(int i=1;i<=n;i++){
            if(i==n||t[i].b!=t[i+1].b){
                int r=i;
                ans+=work(l,r);
                l=r+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}