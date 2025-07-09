#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,k;
int a[maxn],cnt1[maxn],cnt2[maxn],ans[maxn],mx1,mx2;
int main(){
    cin>>T;
    while(T--){
        ans[0]=0;
        cin>>n>>k;
        for(int i=1;i<=n*2;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cnt1[i]=cnt2[i]=0;
        mx1=mx2=0;
        for(int i=1;i<=n;i++)
            cnt1[a[i]]++,mx1=max(mx1,cnt1[a[i]]);
        for(int i=n+1;i<=n*2;i++)
            cnt2[a[i]]++,mx2=max(mx2,cnt2[a[i]]);
        if(mx1==1&&mx2==1){
            for(int i=1;i<=k*2;i++)
                cout<<i<<" ";
            cout<<endl;
            for(int i=1;i<=k*2;i++)
                cout<<i<<" ";
            cout<<endl;
        }else{
            for(int i=1;i<=n;i++){
                if(cnt1[i]==1){
                    ans[++ans[0]]=i;
                }
            }
            if(ans[0]>=k*2){
                for(int i=1;i<=k*2;i++)
                    cout<<ans[i]<<" ";
                cout<<endl;
                for(int i=1;i<=k*2;i++)
                    cout<<ans[i]<<" ";
                cout<<endl;
            }else{
                if(ans[0]%2==1)ans[0]--;
                for(int i=1;i<=ans[0];i++)
                    cout<<ans[i]<<" ";
                int num=k*2-ans[0];
                for(int i=1;i<=n;i++){
                    if(cnt1[i]==2){
                        cout<<i<<" "<<i<<" ";
                        num-=2;
                        if(!num)break;
                    }
                }
                cout<<endl;
                for(int i=1;i<=ans[0];i++)
                    cout<<ans[i]<<" ";
                num=k*2-ans[0];
                for(int i=1;i<=n;i++){
                    if(cnt2[i]==2){
                        cout<<i<<" "<<i<<" ";
                        num-=2;
                        if(!num)break;
                    }
                }
                cout<<endl;
            }
        }
    }
    return 0;
}