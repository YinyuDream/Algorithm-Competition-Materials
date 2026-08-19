#include<bits/stdc++.h>
using namespace std;
int l,r,ans;
int main(){
    cin>>l>>r;
    if(r-l<=100){
        for(int i=l;i<=r;i++){
            if(i%2==1||i%4==0)ans++;
        }
    }else{
        int l2=l,r2=r;
        while(l%4!=0)l++;
        while(r%4!=0)r--;
        ans+=(r-l)/4+1;
        while(l2%2==0)l2++;
        while(r2%2==0)r2--;
        ans+=(r2-l2)/2+1;
    }
    cout<<ans<<endl;
    return 0;
}