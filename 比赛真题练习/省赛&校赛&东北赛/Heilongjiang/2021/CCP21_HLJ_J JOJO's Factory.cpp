#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,mx;
int a[maxn],b[maxn];
int main(){
    cin>>n>>m;
    for(int i=1,l,r;i<=m;i++){
        scanf("%d%d",&l,&r);
        a[l]++,b[r]++;
        mx=max(mx,a[l]);
        mx=max(mx,b[r]);
    }
    if(mx==n)cout<<n-1;
    else cout<<n;
    return 0;
}