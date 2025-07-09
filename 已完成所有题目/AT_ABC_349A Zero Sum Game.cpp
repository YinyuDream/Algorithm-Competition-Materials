#include<bits/stdc++.h>
using namespace std;
int sum,n;
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u;
        cin>>u;
        sum-=u;
    }
    cout<<sum;
    return 0;
}