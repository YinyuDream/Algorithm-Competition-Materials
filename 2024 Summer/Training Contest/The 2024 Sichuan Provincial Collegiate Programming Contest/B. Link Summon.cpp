#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll n;
int num[6];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        int ans=0;
        for(int i=1;i<=5;i++){
            cin>>num[i];
        }
        ans+=min(num[1],num[5]);
        num[1]-=ans;
        num[5]-=ans;
        int t=min(num[2],num[4]);
        ans+=t;
        num[2]-=t;
        num[4]-=t;
        t=num[3]/2;
        ans+=t;
        num[3]%=2;
        int now=num[5];
        for(int i=1;i<=4;i++){
            if(now==0)break;
            t=min(now,num[i]);
            num[i]-=t;
            now-=t;
            ans+=t;
        }
        if(now!=0){
            ans+=now/2;
            cout<<ans<<'\n';
            continue;
        }
        if(num[4]!=0){
            int p=0;
            for(int i=1;i<=3;i++){
                p+=num[i];
            }
            if(p/2>=num[4]){
                p=num[4]*2;
                ans+=p/2;
                num[4]=0;
                for(int i=1;i<=3;i++){
                    if(p==0)break;
                    t=min(p,num[i]);
                    p-=t;
                    num[i]-=t;
                }
            } else {
                t=(p+num[4])/3;
                ans+=t;
                cout<<ans<<'\n';
                continue;
            }
        }
        ans+=(num[3]*3+num[2]*2+num[1])/6;
        cout<<ans<<'\n';
    }
    return 0;
}