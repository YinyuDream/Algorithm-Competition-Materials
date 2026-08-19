#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> t(n+1);
    for(int i=1;i<=n;i++)
        cin>>t[i];
    auto check=[&](long long lim,bool output){
        vector<long long> rem(m+1,0);
        for(int i=1,now=1;i<=n;i++){
            if(rem[now]+t[i]<=lim){
                if(output){
                    cout<<1<<" "<<now<<" "<<rem[now]<<" "<<rem[now]+t[i]<<endl;
                }
                rem[now]+=t[i];
                if(rem[now]==lim){
                    now++;
                    if(now>m&&i<n){
                        return false;
                    }
                }
            }else{
                now++;
                if(now>m){
                    return false;
                }
                if(output){
                    cout<<2<<" "<<now<<" "<<0<<" "<<t[i]-(lim-rem[now-1])<<" "<<now-1<<" "<<rem[now-1]<<" "<<lim<<endl;
                }
                rem[now]+=t[i]-(lim-rem[now-1]);
            }
        }
        return true;
    };
    long long l=*max_element(t.begin(),t.end()),r=1e18;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid,false))r=mid-1;
        else l=mid+1;
    }
    check(l,true);
    return 0;
}