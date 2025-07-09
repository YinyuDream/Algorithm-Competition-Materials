#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n,sign_u,sign_v,sign_w;
ll ans;
struct node{
    ll u,v,w;
}a[maxn];
bool cmp(node p,node q)
{
    return sign_u*p.u+sign_v*p.v+sign_w*p.w>sign_u*q.u+sign_v*q.v+sign_w*q.w;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].u>>a[i].v>>a[i].w;
    for(sign_u=-1;sign_u<=1;sign_u+=2){
        for(sign_v=-1;sign_v<=1;sign_v+=2){
            for(sign_w=-1;sign_w<=1;sign_w+=2){
                sort(a+1,a+n+1,cmp);
                ll sum_u=0,sum_v=0,sum_w=0;
                for(int i=1;i<=n;i++){
                    sum_u+=a[i].u,sum_v+=a[i].v,sum_w+=a[i].w;
                    ans=max(ans,abs(sum_u)+abs(sum_v)+abs(sum_w));
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}