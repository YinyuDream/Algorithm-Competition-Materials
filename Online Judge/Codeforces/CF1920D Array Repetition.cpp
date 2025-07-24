#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,q;
ll op[maxn],x[maxn];
struct node{
    ll l,r,opt,val;
};
vector<node>v;
int find(ll x)
{
    int l=0,r=v.size()-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(v[mid].l<=x&&v[mid].r>=x)
            return mid;
        if(v[mid].l<x)
            l=mid+1;
        else if(v[mid].r>x)
            r=mid-1;
    }
    return r;
}
int main(){
    cin>>T;
    while(T--){
        v.clear();
        cin>>n>>q;
        for(int i=1;i<=n;i++)
            cin>>op[i]>>x[i];
        for(int i=1;i<=n;i++){
            if(op[i]==1){
                if(v.empty()){
                    v.push_back({1,1,1,x[i]});
                }else{
                    node u=v.back();
                    v.push_back({u.r+1,u.r+1,1,x[i]});
                }
            }else{
                node u=v.back();
                ll t=1e18/u.r+1;
                v.push_back({u.r+1,u.r*min(t,x[i]+1),2,u.r});
                if(t<=x[i]+1)
                    goto end;
            }
        }
        end:;
        for(int i=1;i<=q;i++){
            ll k;
            cin>>k;
            while(v[find(k)].opt==2)
                k=(k-1)%v[find(k)].val+1;
            cout<<v[find(k)].val<<" ";
        }
        cout<<endl;
    }
    return 0;
}