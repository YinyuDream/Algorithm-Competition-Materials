#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        int ans=a*40+b*60;
        if(ans%100==0){
            ans/=100;
        }else{
            ans/=100;
            ans+=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}