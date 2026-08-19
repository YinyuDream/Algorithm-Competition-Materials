#include<bits/stdc++.h>
using namespace std;
int q,k,c,n;
int main(){
    cin>>q;
    while(q--){
        int ans=0;
        cin>>k>>c>>n;
        int lim=sqrt(c);
        for(int i=1;i<=lim;i++){
            if(c%i==0){
                int b=i;
                if((c-b)%k==0&&__gcd((c-b)/k,b)>=n)
                    ans++;
                if(i!=1&&i*i!=c){
                    b=c/i;
                    if((c-b)%k==0&&__gcd((c-b)/k,b)>=n)
                        ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
     
    return 0;
}