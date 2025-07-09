#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,l,r,a[N];
int main(){
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
        a[i]=i;
    reverse(a+l,a+r+1);
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    return 0;
}