#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m;
vector<int>a[maxn];
int main(){
    for(int i=1;i<=2e3;i++)
        for(int j=1;j<=2e3;j++)
            if(__gcd(i,j)==1)
                a[i].push_back(j);
    cin>>T;
    while(T--){
        ll ans=0;
        cin>>n>>m;
        int lim=1e3;
        int mx=min(n,m);
        for(int g=2;g<=lim;g++){
            for(int l=1;l<g;l++){
                if(__gcd(l,g-l)==1){
                    ll coe_a=g-l;
                    ll coe_b=l;
                    ans+=min(n/(coe_a*g),m/(coe_b*g));
                }
            }
        }
        for(int g=lim+1;g<=mx;g++){
            for(int ka=1;g*ka<=n;ka++){
                for(int t=0;g*a[ka][t]<=m&&t<a[ka].size();t++){
                    int b=g*a[ka][t],a=g*ka;
                    if(b*g%(a+b)==0)
                        ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}