#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]>b[i]){
                for(int j=n;j>i;j--)
                    a[j]=a[j-1];
                a[i]=b[i];
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}