#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
template <typename _Tp> inline void read(_Tp&x) {
    char ch;bool flag=0;x=0;
    while(ch=getchar(),!isdigit(ch)) if(ch=='-')flag=1;
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    if(flag) x=-x;
}
ll work(__int128 n,__int128 k,__int128 m,ll a)
{
    if(n%m==0)return 0;
    __int128 pow_k=k,sum=1;
    for(int i=1;i<=31;i++){
        __int128 l=pow_k*n;
        __int128 r=l+sum*(k-1);
        if(l%m==0||l/m!=r/m)
            return i*a;
        sum+=pow_k;
        pow_k*=k;
    }
}
int main(){
    cin>>T;
    while(T--){
        ll n,k,m,a,b;
        read(n),read(k),read(m),read(a),read(b);
        if(k==1){
            cout<<(n%m==0?0:-1)<<endl;
            continue;
        }
        ll ans=1e18,cnt_b=0;
        while(n){
            ans=min(ans,work(n,k,m,a)+cnt_b*b);
            n/=k;
            cnt_b++;
        }
        ans=min(ans,work(n,k,m,a)+cnt_b*b);
        cout<<ans<<endl;
    }
    return 0;
}