#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],b[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        int ans=0,cnt=0;
        for(int i=1;i<=n;i++)
            if(a[i]>b[i])
                ans++;
            else if(a[i]==b[i])
                cnt++;
        cout<<ans+(cnt+1)/2<<endl;
    }
    return 0;
}