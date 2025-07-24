#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m,k,ans;
int a[maxn],b[maxn];
int main(){
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++)
            cin>>b[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i]+b[j]<=k)
                    ans++;
        cout<<ans<<endl;
    }
    return 0;
}