#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int t[maxn];
struct node{
    int spd,wt;
}a[maxn],b[maxn];
bool check(int lim)
{
    for(int i=1;i<=n;i++)
        b[i].spd=a[i].spd,b[i].wt=a[i].wt;
    int pos=lower_bound(t+1,t+n+1,lim)-t;
    if(pos==1)return true;
    sort(b+1,b+pos,[](node x,node y){return x.wt>y.wt;});
    sort(b+pos,b+n+1,[](node x,node y){return x.wt+x.spd<y.wt+y.spd;});
    int l=1;
    for(int i=n;i>=pos;i--){
        if(b[l].wt+lim<=b[i].wt+b[i].spd){
            l++;
            if(l==pos)return true;
        }else return false;
    }
    if(l<pos)return false;
    return true;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int l=1e9,r=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].spd>>a[i].wt;
            l=min(l,a[i].spd);
            r=max(r,a[i].spd);
            t[i]=a[i].spd;
        }
        sort(a+1,a+n+1,[](node x,node y){return x.spd<y.spd;});
        sort(t+1,t+n+1);
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid))l=mid+1;
            else r=mid-1;
        }
        cout<<r<<endl;
    }
    return 0;
}