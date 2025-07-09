#include<bits/stdc++.h>
using namespace std;
int l1,r1,l2,r2,T;
int find(int x)
{
    int ans=0;
    while(x){
        ans=max(ans,x%10);
        x/=10;
    }
    return ans;
}
int main(){
    cin>>T;
    while(T--){
        cin>>l1>>r1>>l2>>r2;
        if(r1-l1>=10||r2-l2>=10){
            cout<<9<<endl;
        }else{
            int ans=0;
            for(int i=l1;i<=r1;i++){
                for(int j=l2;j<=r2;j++){
                    ans=max(ans,find(i+j));
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}