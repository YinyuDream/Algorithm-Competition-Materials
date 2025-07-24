#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int l=1,r=1000;
    while(l<r){
        int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
        cout<<"?"<<" "<<lmid<<" "<<rmid<<endl;
        cout.flush();
        int x;
        cin>>x;
        if(x==lmid*rmid)l=rmid+1;
        else if(x==lmid*(rmid+1)){
            l=lmid+1;
            r=rmid;
        }else{
            r=lmid;
        }
    }
    cout<<"! "<<l<<endl;
    cout.flush();
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}