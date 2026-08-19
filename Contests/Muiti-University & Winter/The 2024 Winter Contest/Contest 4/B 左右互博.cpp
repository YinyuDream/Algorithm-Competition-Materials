#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn],f[maxn];
long long sum;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i]-1;
    }
    if(sum%2==1){
        cout<<"gui";
    }else{
        cout<<"sweet";
    }
    return 0;
}