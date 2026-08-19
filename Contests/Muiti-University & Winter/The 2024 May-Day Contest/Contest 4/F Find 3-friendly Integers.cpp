#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll l,r;
bool check(int val)
{
    if(val<10){
        if(val%3==0)return true;
        else return false;
    }else{
        if(val%3==0)return true;
        if((val/10)%3==0)return true;
        if((val%10)%3==0)return true;
        return false;
    }
}
int main(){
    cin>>T;
    while(T--){
        cin>>l>>r;
        ll ans=0;
        if(r<=99){
            for(int i=l;i<=r;i++)
                ans+=check(i);
        }else if(l>=100){
            ans=r-l+1;
        }else{
            for(int i=l;i<=99;i++)
                ans+=check(i);
            ans+=r-99;
        }
        cout<<ans<<endl;
    }
    return 0;
}