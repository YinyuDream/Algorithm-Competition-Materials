#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[6],sum=0;
    for(int i=0;i<6;i++)
        cin>>a[i],sum+=a[i];
    
    if(a[0]*30<sum)cout<<"Yes";
    else cout<<"No";
    return 0;
}