#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,r,ans;
int a[maxn],cnt[5];
int main(){
    cin>>n>>k;
    ans=n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        while(r<=n&&(cnt[1]==0||cnt[2]==0||cnt[3]==0||cnt[4]<k)){
            r++;
            cnt[a[r]]++;
        }
        if(r>n)break;
        ans=min(ans,r-i+1);
        cnt[a[i]]--;
    }
    cout<<ans<<endl;
    return 0;
}