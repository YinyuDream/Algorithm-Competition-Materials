#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,ans;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=2;i<n;i++){
            if(a[i-1]>0){
                a[i]-=2*a[i-1];
                a[i+1]-=a[i-1];
                a[i-1]=0;
            }
        }
        ans=1;
        for(int i=1;i<=n;i++)
            if(a[i]!=0)
                ans=0;
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}