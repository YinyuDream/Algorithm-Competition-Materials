#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int a[maxn],sum[maxn];
int prime[maxn],not_prime[maxn],cnt;
void get_prime(){
    not_prime[1]=1;
    for(int i=2;i<maxn;i++){
        if(!not_prime[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<maxn;j++){
            not_prime[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void solve(){
    int n=read(),k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum[i]=sum[i-1]+a[i];
    }
    int l=-1e9,r=1e9;
    auto check=[&](int mid){
        set<pair<int,int>> s;
        s.insert({0,0});
        int cnt=0;
        for(int i=1;i<=n;i++){
            auto it=s.lower_bound({sum[i]-mid,i});
            for(auto j=s.begin();j!=it;j++){
                if(!not_prime[i-j->second]){
                    cnt++;
                    s.clear();
                    break;
                }
            }
            s.insert({sum[i],i});
        }
        return cnt>=k;
    };
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    if(r>-1e9){
        cout<<r<<endl;
    }else{
        cout<<"impossible"<<endl;
    }
}
int main(){
    get_prime();
    int T=read();
    while(T--){
        solve();
    }
    return 0;
}