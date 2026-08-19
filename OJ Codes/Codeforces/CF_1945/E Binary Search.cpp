#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,x;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>x;
        for(int i=1;i<=n;i++) cin>>a[i];
        int l=1,r=n+1;
        while(r-l>1){
            int mid=(l+r)>>1;
            if(a[mid]<=x) l=mid;
            else r=mid;
        }
        int pos=0;
        for(int i=1;i<=n;i++)
            if(a[i]==x) pos=i;
        if(l==pos)cout<<0<<endl;
        else cout<<1<<endl<<l<<" "<<pos<<endl;
    }
    return 0;
}