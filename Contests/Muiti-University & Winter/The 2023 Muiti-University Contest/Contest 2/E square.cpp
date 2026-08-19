#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll x,max_k;
ll pow10[20];
int main(){
    pow10[0]=1;
    for(int i=1;i<20;i++)
        pow10[i]=pow10[i-1]*10;
    cin>>T;
    while(T--){
        cin>>x;
        for(int i=0;i<20;i++){
             if(pow10[i]>x){
                max_k=18-i;
                break;
            }
        }
        for(int i=0;i<=max_k;i++){
            ll l=(ll)sqrt(pow10[i]*x)-1,r=(ll)sqrt(pow10[i]*(x+1)-1)+1;
            for(ll j=l;j<=r;j++){
                if(j*j-pow10[i]*x>=0&&j*j-pow10[i]*x<=pow10[i]-1){
                    cout<<j<<endl;
                    goto flag;
                }
            }
        }
        cout<<"-1"<<endl;
        flag:;
    }
    return 0;
}