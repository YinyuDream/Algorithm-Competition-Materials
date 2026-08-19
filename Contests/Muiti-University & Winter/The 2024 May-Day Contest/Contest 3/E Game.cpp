#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn];
bool check(int val)
{
    long long num=0;
    for(int i=1;i<=n;i++){
        num+=a[i]-val;
        if(num>0)return false;
    }
    return true;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int l=0,r=1e9;
        check(4);
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid))r=mid-1;
            else l=mid+1;
        }
        cout<<l<<endl;
    }
    return 0;
}