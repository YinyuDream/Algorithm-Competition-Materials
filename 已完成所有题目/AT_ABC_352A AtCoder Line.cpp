#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
    cin>>n>>a>>b>>c;
    if(a>b)swap(a,b);
    if(c>=a&&c<=b)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}