#include<bits/stdc++.h>
using namespace std;
const int mod=4933;
int ksm(int a,int b){
    if(b==0){
        return 1;
    }
    int ans=ksm(a,b/2);
    ans=ans*ans%mod;
    if(b&1){
        ans=ans*a%mod;
    }
    return ans;
}
class frac{
    private:
        int a,b;
    public:
        frac(){
            a=0,b=1;
        }
        frac(int _a,int _b){
            a=_a,b=_b;
        }
        int integer(){
            return a*ksm(b,mod-2)%mod;
        }
        bool operator<(const frac &v){
            return a*v.b<v.a*b;
        }
};
int main(){
    int n,m,k,a,l;
    cin>>n>>m>>k>>a>>l;
    vector<int> x(k);
    vector<frac> s(k);
    for(int i=0;i<k;i++){
        int u,v;
        cin>>x[i]>>u>>v;
        s[i]=frac(u,v);
    }
    int ans=a%mod,now=1;
    for(int i=k-1;i>=0;i--){
        if(x[i]==0){
            continue;
        }
        now*=(1-s[i].integer());
        now%=mod;
    }
    cout<<((ans+now)%mod+mod)%mod;
    return 0;
}