#include<bits/stdc++.h>
using namespace std;
const int maxn=1e8+10;
int n;
int a[maxn];
int main(){
    cin>>n;
    a[1]=n*6;
    for(int i=2;i<=n+1;i++)
        a[i]=3+5*(n-i+1)+4*(i/2-1);
    for(int i=n+2;i<=n*2;i++)
        a[i]=4*(n-(i-1)/2);
    for(int i=1;i<=n*2;i++){
        a[i+1]+=a[i]/10;
        a[i]%=10;
    }
    int mx=n*2+1;
    while(a[mx]>=10){
        a[mx+1]=a[mx]/10;
        a[mx]%=10;
        mx++;
    }
    while(a[mx]==0)
        mx--;
    for(int i=mx;i;i--)
        cout<<a[i];
    return 0;
}