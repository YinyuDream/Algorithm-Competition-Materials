#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int l=1,r=2,ans=0;
    for(int i=1;i<=q;i++){
        char c;
        int d;
        cin>>c>>d;
        if(c=='L'){
            if(l<=d){
                if(r>=l&&r<=d){
                    ans+=l+n-d;
                }else{
                    ans+=d-l;
                }
            }else{
                if(r>=d&&r<=l){
                    ans+=d+n-l;
                }else{
                    ans+=l-d;
                }
            }
            l=d;
        }else{
            if(r<=d){
                if(l>=r&&l<=d){
                    ans+=r+n-d;
                }else{
                    ans+=d-r;
                }
            }else{
                if(l>=d&&l<=r){
                    ans+=d+n-r;
                }else{
                    ans+=r-d;
                }
            }
            r=d;
        }
    }
    cout<<ans<<endl;
    return 0;
}