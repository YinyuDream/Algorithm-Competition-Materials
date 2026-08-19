#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k;
int a[maxn];
long long sum;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum<k){
        cout<<0;
    }else{
        cout<<sum-k+k/2;
    }
    return 0;
}