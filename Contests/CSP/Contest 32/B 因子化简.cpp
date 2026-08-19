#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int q,k;
ll n;
int prime[maxn],not_prime[maxn],tot;
void init(){
    for(int i=2;i<maxn;i++){
        if(!not_prime[i]) prime[++tot]=i;
        for(int j=1;j<=tot&&i*prime[j]<maxn;j++){
            not_prime[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int fac[maxn],num[maxn],cnt;
int main(){
    init();
    cin>>q;
    while(q--){
        cin>>n>>k;
        ll origin_n=n;
        cnt=0;
        for(int i=1;i<=tot;i++){
            if(n%prime[i]==0){
                fac[++cnt]=prime[i];
                num[cnt]=0;
                while(n%prime[i]==0){
                    n/=prime[i];
                    num[cnt]++;
                }
            }
        }
        origin_n/=n;
        for(int i=1;i<=cnt;i++){
            if(num[i]<k){
                for(int j=1;j<=num[i];j++){
                    origin_n/=fac[i];
                }
            }
        }
        cout<<origin_n<<endl;
    }
    return 0;
}