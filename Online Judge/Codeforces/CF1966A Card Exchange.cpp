#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e2+10;
int T,n,k;
int a[maxn],cnt[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
            cnt[a[i]]++;
        bool flag=true;
        for(int i=1;i<=100;i++){
            if(cnt[i]>=k){
                flag=false;
            }
        }
        if(!flag)cout<<k-1<<endl;
        else cout<<n<<endl;
    }
    return 0;
}