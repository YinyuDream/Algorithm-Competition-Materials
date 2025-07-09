#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r;
    cin>>l>>r;
    int ans=0;
    auto check=[&](int x){
        vector<int> v;
        for(int i=0;i<6;i++){
            v.push_back(x%10);
            x/=10;
        }
        if(count(v.begin(),v.end(),0)>=1){
            return false;
        }
        for(int i=0;i<(1<<6);i++){
            if(__builtin_popcount(i)!=3){
                continue;
            }
            vector<int> a,b;
            for(int j=0;j<6;j++){
                if(i&(1<<j)){
                    a.push_back(v[j]);
                }else{
                    b.push_back(v[j]);
                }
            }
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            if(a[0]+a[1]>a[2]&&b[0]+b[1]>b[2]){
                return true;
            }
        }
        return false;
    };
    for(int i=l;i<=r;i++){
        if(check(i)){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}