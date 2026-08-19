#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int a[4];
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        sort(a,a+4);
        cout<<(a[0]==a[3]?"NO":"YES")<<endl;
    }
    return 0;
}