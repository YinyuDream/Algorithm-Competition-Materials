#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,m,cnt;
struct node{
    int val,id;
}a[maxn];
vector<node>v;
bool operator<(node u,node v)
{
    return u.val<v.val;
}
int num[maxn],tot;
int main(){
    cin>>n>>m;
    for(int i=1,k;i<=n;i++){
        cin>>k;
        for(int j=1,v;j<=k;j++){
            cin>>v;
            a[++cnt]={v,i};
        }
    }
    sort(a+1,a+cnt+1);
    int r=0,ans=1e9;
    for(int i=1;i<=cnt;i++){
        while(tot<m&&r<=cnt){
            r++;
            num[a[r].id]++;
            if(num[a[r].id]==1)
                tot++;
        }
        if(r<=cnt)ans=min(ans,a[r].val-a[i].val);
        num[a[i].id]--;
        if(!num[a[i].id])
            tot--;
    }
    cout<<ans<<endl;
    return 0;
}