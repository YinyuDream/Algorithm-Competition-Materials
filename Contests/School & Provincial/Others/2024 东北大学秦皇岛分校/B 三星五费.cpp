#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    if(n<8)cout<<"0.000";
    else{
        n-=5;
        if(n&1)n--;
        n/=2;
        double a=1,ans=0;
        for(int i=1;i<=n;i++){
            ans+=0.03*a;
            a*=0.97;
        }
        printf("%.3f",ans);
    }
    return 0;
}