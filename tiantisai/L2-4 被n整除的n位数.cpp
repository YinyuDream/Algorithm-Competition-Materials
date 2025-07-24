#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pw10[16];
bool check(ll n,int x){
    while(x){
        if(n%x!=0){
            return false;
        }
        n/=10,x--;
    }
    return true;
}
int main(){
    pw10[0]=1;
    for(int i=1;i<=15;i++)
        pw10[i]=pw10[i-1]*10;
    ll n;
    cin>>n;
    ll l,r;
    cin>>l>>r;
    l=max(l,pw10[n-1]);
    int now=l;
    int tot=ans.size();
    for(int i=0;i<=tot-1;i++){
        cout<<ans<<endl;
    }
}