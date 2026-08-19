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
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int ans=3;
        for(int i=1;i<=n;i++)
            if(a[a[i]]==i)
                ans=2;
        cout<<ans<<endl;
    }
    return 0;
}