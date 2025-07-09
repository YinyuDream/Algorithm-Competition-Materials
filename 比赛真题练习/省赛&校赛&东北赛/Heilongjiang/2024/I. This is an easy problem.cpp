#include<bits/stdc++.h>
using namespace std;
int x;
int main(){
    cin>>x;
    int cnt=0;
    while(x){
        cnt+=x%2;
        x/=2;
    }
    cout<<cnt<<endl;
    return 0;
}