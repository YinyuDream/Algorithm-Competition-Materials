#include<bits/stdc++.h>
using namespace std;
long long t,a,k,l,r;
int main(){
    cin>>t>>a>>k;
    l=min(t,0ll)-k,r=max(t,0ll)+k;
    if(l<=a&&r>=a)cout<<abs(a)+abs(a-t);
    else cout<<abs(t)+abs(a-t)*2;
}