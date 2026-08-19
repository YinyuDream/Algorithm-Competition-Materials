#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
const int maxn=1e6+10;
const ll p1=399999959,p2=399999949;
void ex_gcd(i128 a,i128 b,i128 &x,i128 &y){
	if(b==0){
		x=1,y=0;
		return ;
	}
	ex_gcd(b,a%b,x,y);
	i128 z=x;x=y;y=z-(a/b)*y;
}
void solve(){
    auto ask=[&](ll val){
        cout<<"? "<<val<<endl;
        cout.flush();
        ll res;
        cin>>res;
        return res;
    };
    i128 mod1=ask(p1),mod2=ask(p2),sum=p1*p2;
    i128 m[]={p1,p2};
    i128 a[]={mod1,mod2};
    i128 ans=0;
    i128 b[]={m[1],m[0]};
    i128 t[]={0,0};
    i128 tmp=0;
    for(int i=0;i<2;i++)
        ex_gcd(b[i],m[i],t[i],tmp);
    for(int i=0;i<2;i++)
        ans=(ans+a[i]*b[i]*(t[i]>0?t[i]:(t[i]+m[i])))%sum;
    cout<<"! "<<(ll)ans<<endl;
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