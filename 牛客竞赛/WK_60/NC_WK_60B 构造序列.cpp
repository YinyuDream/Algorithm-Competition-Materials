#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(n<m){
        swap(n,m);
    }
    cout<<m+min(m+1,n);
    return 0;
}