#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        long long a,b,c,d,a1;
        cin>>a>>b>>c>>d;
        a1=1.0*c/d*b;
        while(a1*d>=c*b){
            a1--;
        }
        while((a1+1)*d<c*b){
            a1++;
        }
        cout<<a-a1<<" ";
    }
    return 0;
}