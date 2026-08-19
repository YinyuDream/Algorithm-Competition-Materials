#include<bits/stdc++.h>
using namespace std;
int sum_a,sum_b;
int a[10],b[10];
int main(){
    for(int i=1;i<=9;i++){
        cin>>a[i];
        sum_a+=a[i];
    }
    for(int i=1;i<=8;i++){
        cin>>b[i];
        sum_b+=b[i];
    }
    cout<<sum_a-sum_b+1<<endl;
    return 0;
}