#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];

int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n*2;i++)
            cin>>a[i];
        sort(a+1,a+1+n*2);
        if(n==1){
            cout<<a[2]-a[1]<<endl;
            continue;
        }
        if(n%2==1){
            ll ans=0;
            for(int i=1;i<=n*2;i++)
                ans+=abs(a[i]);
            cout<<ans<<endl;
        }else{
            ll sum=0,ans=1e18,num=0;
            for(int i=1;i<=n*2;i++)
                sum+=abs(a[i]+1);
            for(int i=1;i<=n*2;i++)
                ans=min(ans,sum-abs(a[i]+1)+abs(a[i]-n));
            for(int i=1;i<=n*2;i++)
                num+=abs(a[i]);
            ans=min(ans,num);
            if(n==2){
                num=0;
                for(int i=1;i<=n*2;i++)
                    num+=abs(a[i]-2);
                ans=min(ans,num);
            }
            cout<<ans<<endl;
        }
        
    }
    return 0;
}