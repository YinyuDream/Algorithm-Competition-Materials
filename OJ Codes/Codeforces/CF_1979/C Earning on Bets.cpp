#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=110;
int T,n;
ll f[maxn],ans[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>f[i];
        bool flag=false;
        for(ll i=1e9;i<=1e9;i++){
            ll val=0;
            for(int j=1;j<=n;j++){
                val+=i/f[j]+1;
                ans[j]=i/f[j]+1;
            }
            if(val<=i){
                ans[n]+=i-val;
                for(int j=1;j<=n;j++)
                    cout<<ans[j]<<" ";
                cout<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
            cout<<-1<<endl;
    }
    return 0;
}