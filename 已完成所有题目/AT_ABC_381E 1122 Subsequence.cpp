#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    s=" "+s;
    vector<int> sum1(n+1,0),sum2(n+1,0),sum3(n+1,0),nxt(n+2,0);
    for(int i=1;i<=n;i++){
        sum1[i]=sum1[i-1]+(s[i]=='1');
        sum2[i]=sum2[i-1]+(s[i]=='2');
        sum3[i]=sum3[i-1]+(s[i]=='/');
    }
    nxt[n+1]=n+1;
    for(int i=n;i;i--){
        if(s[i]=='/'){
            nxt[i]=i;
        }else{
            nxt[i]=nxt[i+1];
        }
    }
    auto work=[&](int L,int R){
        if(sum3[R]-sum3[L-1]==0){
            return 0;
        }
        int l=0,r=min(sum1[R]-sum1[L-1],sum2[R]-sum2[L-1]);
        auto check=[&](int len){
            if(len==0){
                return true;
            }
            int lef=L,rig=R;
            while(lef<=rig){
                int mid=(lef+rig)>>1;
                if(sum1[mid]-sum1[L-1]>=len){
                    rig=mid-1;
                }else{
                    lef=mid+1;
                }
            }
            int pos=nxt[lef+1];
            if(pos>R){
                return false;
            }
            return sum2[R]-sum2[pos-1]>=len;
        };
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return 2*r+1;
    };
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<work(l,r)<<endl;
    }
    return 0;
}