#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn],cnt[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cnt[i]=0;
        for(int i=1;i<=n;i++)
            cnt[a[i]]++;
        int ans=0;
        for(int i=1;i<=n;i++)
            if(cnt[i]==2)
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}