#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],cnt[maxn],mx;
int main(){
    cin>>T;
    while(T--){
        mx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],cnt[i]=0,mx=max(mx,a[i]);
        cnt[0]=cnt[n+1]=0;
        for(int i=1;i<=n;i++)
            cnt[a[i]]++;
        if(cnt[0]==0){
            cout<<0<<endl;
            continue;
        }
        int ans=0,num=0;
        for(int i=0;i<=n;i++){
            if(cnt[i]==1){
                num++;
                if(num==2){
                    ans=i;
                    break;
                }
            }
        }
        if(num<=1){
            ans=mx+1;
        }
        for(int i=1;i<=n;i++){
            if(cnt[i]==0){
                ans=min(ans,i);
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}