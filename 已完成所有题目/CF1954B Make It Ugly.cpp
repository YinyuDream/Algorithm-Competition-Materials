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
        a[n+1]=0;
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[1]){
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<-1<<endl;
            continue;
        }
        int lst=1,ans=n+1;
        for(int i=1;i<=n+1;i++){
            if(a[i]!=a[1]){
                ans=min(ans,i-lst);
                lst=i+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}