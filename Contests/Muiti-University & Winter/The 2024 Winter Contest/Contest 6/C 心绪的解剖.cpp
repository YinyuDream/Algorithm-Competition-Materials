#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=50;
struct node{
    ll a,b,c;
    node(ll _a,ll _b,ll _c){
        a=_a,b=_b,c=_c;
    }
};
int q;
ll n;
ll f[maxn];
map<ll,node>mp;
int main(){
    f[1]=f[2]=1;
    for(int i=3;i<maxn;i++)
        f[i]=f[i-1]+f[i-2];
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            for(int k=0;k<maxn;k++){
                ll num=f[i]+f[j]+f[k];
                node fr=node(f[i],f[j],f[k]);
                if(mp.find(num)==mp.end()){
                    mp.insert(make_pair(num,fr));
                }
            }
        }
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>n;
        auto ans=mp.find(n);
        if(ans==mp.end()){
            cout<<"-1"<<endl;
        }else{
            node t=ans->second;
            cout<<t.a<<" "<<t.b<<" "<<t.c<<endl;
        }
    }
    return 0;
}