#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m,k;
int a[maxn],cnt[maxn],sum[maxn];
struct node{
    int id,val;
}t[maxn];
bool operator<(node u,node v)
{
    if(u.val!=v.val)return u.val<v.val;
    else return u.id>v.id;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            cnt[i]=0;
            cin>>a[i];
            t[i].id=i;
            t[i].val=a[i];
        }
        sort(t+1,t+n+1);
        int pos=1;
        while(k>0){
            if(k-m>=0){
                k-=m;
                cnt[t[pos].id]=m;
            }else{
                cnt[t[pos].id]=k;
                k=0;
            }
            pos++;
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+cnt[i];
        for(int i=1;i<=n;i++)
            ans+=(1ll*a[i]+sum[i-1])*cnt[i];
        cout<<ans<<endl;
    }
    return 0;
}