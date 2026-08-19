#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int q;
    cin>>q;
    vector<ll> a,sum;
    a.push_back(0),sum.push_back(0);
    vector<double> val,ans,maxans;
    val.push_back(0),ans.push_back(0),maxans.push_back(0);
    int pos=0,cnt=0;
    cout<<fixed<<setprecision(10);
    for(int i=0;i<q;i++){
        int op;
        cin>>op;
        if(op==1){
            int x;
            cin>>x;
            a.push_back(x);
            sum.push_back(sum.back()+x);
            cnt++;
            while(pos+1<=cnt-1&&(1.0*sum[pos+1]+a.back())/(pos+2)<(1.0*sum[pos]+a.back())/(pos+1)){
                pos++;
            }
            val.push_back((1.0*sum[pos]+a.back())/(pos+1));
            ans.push_back(a.back()-val.back());
            maxans.push_back(max(maxans.back(),ans.back()));
        }else{
            cout<<maxans.back()<<endl;
        }
    }
}
int main(){
    solve();
    return 0;
}