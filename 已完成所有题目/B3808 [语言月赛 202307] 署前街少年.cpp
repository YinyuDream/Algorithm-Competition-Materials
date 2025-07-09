#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+10;
int n,k;
int a[maxn];
long long sum[maxn];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n*2;i++)
        cin>>a[i];
    for(int i=1;i<=n*2;i++){
        sum[i%k]+=a[i];
    }
    for(int i=1;i<=n*2;i++){
        if(i%2==0){
            cout<<a[i]<<" "; 
        }else{
            cout<<sum[i%k]%i<<" ";
        }
    }
    return 0;
}