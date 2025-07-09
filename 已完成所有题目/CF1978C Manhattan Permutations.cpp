#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int a[maxn];
ll k;
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            a[i]=i;
        int l=1,r=n;
        while(l<=r){
            if(k==0)
                break;
            if(abs(a[r]-l)+abs(a[l]-r)<=k){
                k-=abs(a[r]-l)+abs(a[l]-r);
                swap(a[l],a[r]);
                l++;
                r--;
            }else{
                l++;
            }
        }
        if(k!=0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
                cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}