#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n;
int a[maxn];
ll sum,lim;
set<ll> st;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++)
        sum+=a[i];
    lim=sqrt(sum)+1;
    for(ll i=1;i<=lim;i++){
        if(sum%i==0){
            if(sum/i>=n){
                st.insert(i);
            }
            if(i>=n){
                st.insert(sum/i);
            }
        }
    }
    cout<<st.size();
    return 0;
}