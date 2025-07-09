#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
set<ll>s;
ll T,a,b,l,lim=20;
ll fast_pow(ll _a,ll _b)
{
	if(_b==0)return 1ll;
	ll _c=fast_pow(_a,_b/2);
	_c=_c*_c;
	if(_b&1)_c=_a*_c;
	return _c;
}
int main(){
	cin>>T;
	while(T--){
        s.clear();
		cin>>a>>b>>l;
        for(ll i=0;i<=lim;i++){
            ll out=fast_pow(a,i);
            if(out>l)break;
            for(ll j=0;j<=lim;j++){
                ll num=out*fast_pow(b,j);
                if(num>l)break;
                if(l%num==0)s.insert(l/num);
            }
        }
        cout<<s.size()<<endl;
	}
	return 0;
}