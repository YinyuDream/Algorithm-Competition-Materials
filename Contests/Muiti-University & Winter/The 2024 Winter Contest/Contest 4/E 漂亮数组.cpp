#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,k,cnt,lim,ans;
int a[maxn],mx[maxn];
ll sum[maxn];
unordered_map<int,int>mp;
vector<int>pos[maxn];
struct node{
    int l,r;
}seg[maxn];
bool cmp(node p,node q)
{
    if(p.r!=q.r)return p.r<q.r;
    else return p.l>q.l;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]%=k;
    }
    for(int i=1;i<=n;i++){
        sum[i]=(sum[i-1]+a[i])%k;
        if(mp.find(sum[i])==mp.end()){
            mp[sum[i]]=++cnt;
        }
        pos[mp[sum[i]]].push_back(i);
    }
    memset(mx,-1,sizeof mx);
    for(int i=1;i<=n;i++){
        if(mp.find(sum[i-1])!=mp.end()){
            auto it=lower_bound(pos[mp[sum[i-1]]].begin(),pos[mp[sum[i-1]]].end(),i);
            if(it!=pos[mp[sum[i-1]]].end()){
                mx[i]=*it;
            }
        }
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        if(mx[i]!=-1){
            seg[++cnt]={i,mx[i]};
        }
    }
    sort(seg+1,seg+cnt+1,cmp);
    for(int i=1;i<=cnt;i++){
        if(seg[i].l>lim){
            ans++;
            lim=seg[i].r;
        }
    }
    cout<<ans;
    return 0;
}