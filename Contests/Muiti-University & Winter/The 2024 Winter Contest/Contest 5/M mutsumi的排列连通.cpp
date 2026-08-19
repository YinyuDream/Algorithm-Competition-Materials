#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,ans;
int a[maxn],b[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        if(n==2){
            if(a[1]==b[1]){
                cout<<-1<<endl;
            }else{
                cout<<1<<endl;
            }
            continue;
        }
        ans=2;
        for(int i=2;i<n;i++){
            if(a[i]==b[i]){
                ans=min(ans,1);
            }
        }
        for(int i=1;i<n;i++){
            if(a[i]==b[i+1]||a[i+1]==b[i]){
                ans=min(ans,1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}