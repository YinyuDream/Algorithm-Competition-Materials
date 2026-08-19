#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    int num=(n+1)/2;
    if(n%k==0){
        if(num%(n/k)==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }else{
        int a=n%k,b=k-n%k;
        int l=0,r=k;
        while(l<=r){
            int mid=(l+r)/2;
            if(n/k*mid+max(0,mid-b)<=num){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        int lower=r;
        l=0,r=k;
        while(l<=r){
            int mid=(l+r)/2;
            if(n/k*mid+min(a,mid)>=num){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        int upper=l;
        if(lower>=upper){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
int n,k;
    cin>>n>>k;
    if(k>n/2){
        cout<<"YES"<<endl;
    }else{
        if(k%2==0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
*/