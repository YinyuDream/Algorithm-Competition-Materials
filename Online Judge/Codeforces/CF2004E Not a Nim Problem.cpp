#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxa=1e7+10;
int not_prime[maxa],prime[maxa],tot;
map<int,int> mp;
void init()
{
    for(int i=2;i<maxa;i++){
        if(!not_prime[i]){
            prime[++tot]=i;
        }
        for(int j=1;j<=tot&&i*prime[j]<maxa;j++){
            not_prime[i*prime[j]]=1;
            if(i%prime[j]==0){
                break;
            }
        }
    }
    for(int i=1;i<=tot;i++){
        mp[prime[i]]=i;
    }
}
int work(int x)
{
    if(!not_prime[x]){
        return x;
    }else{
        for(int i=1;i<=tot;i++){
            if(x%prime[i]==0){
                return prime[i];
            }
        }
    }
}
void solve(){
    int n,val=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            val^=1;
            continue;
        }
        if(a[i]%2==0)continue;
        val^=mp[work(a[i])];
    }
    cout<<(val?"Alice":"Bob")<<endl;
}
int main(){
    init();
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}