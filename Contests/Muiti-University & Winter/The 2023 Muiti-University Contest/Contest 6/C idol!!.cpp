#include<bits/stdc++.h>
using namespace std;
const int maxn=61;
typedef long long ll;
ll n;
ll pw5[maxn];
int main(){
    cin>>n;
    pw5[0]=1;
    for(int i=1;i<maxn;i++){
        pw5[i]=pw5[i-1]*5;
        if(pw5[i]>n)
            break;
    }
    ll cnt5=0;
    for(int i=1;pw5[i]<=n;i++){
        ll lst=n-n%pw5[i],num=(lst-pw5[i])/pw5[i]+1;
        cnt5+=(n/pw5[i])*(n/2)-((pw5[i]+lst)*num/2-num)/2+(num>3);
    }
    if(n%2==1)
        for(int i=1;pw5[i]<=n;i++)
            cnt5+=n/pw5[i]-n/(pw5[i]*2);
    cout<<cnt5;
    return 0;
}