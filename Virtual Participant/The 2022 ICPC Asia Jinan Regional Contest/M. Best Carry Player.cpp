#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
class BigInteger{
    private:
        vector<int> num;
    public:
        BigInteger(int x){
            num.clear();
            while(x){
                num.push_back(x%10);
                x/=10;
            }
            if(num.empty()) num.push_back(0);
        }
        pair<BigInteger,int> operator+(const BigInteger &b){
            int tot=0;
            BigInteger res(0);
            res.num.clear();
            int carry=0;
            for(int i=0;i<max(num.size(),b.num.size());i++){
                int x=i<num.size()?num[i]:0;
                int y=i<b.num.size()?b.num[i]:0;
                res.num.push_back((x+y+carry)%10);
                carry=(x+y+carry)/10;
                tot+=carry;
            }
            if(carry) res.num.push_back(carry);
            return make_pair(res,tot);
        }
};
void solve(){
    int n;
    cin>>n;
    vector<BigInteger> a(n+1,0);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=BigInteger(x);
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        pair<BigInteger,int> res=a[i]+a[i-1];
        ans+=res.second;
        a[i]=res.first;
    }
    cout<<ans<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}