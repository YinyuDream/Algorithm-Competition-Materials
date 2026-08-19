#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll b,n;
ll pwb[maxn];
int phi(int x)
{
    int res=x;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            res=res/i*(i-1);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) res=res/x*(x-1);
    return res;
}
int main(){
    pwb[0]=1;
    cin>>T;
    while(T--){
        cin>>b>>n;
        int lim=phi(n);
        for(int i=1;i<=lim;i++)
            pwb[i]=pwb[i-1]*b%n;
        if(__gcd(b,n)!=1){
            bool flag=0;
            for(int i=0;i<=lim;i++){
                if(pwb[i]==0){
                    cout<<1<<" "<<i<<endl;
                    flag=1;
                    break;
                }
            }
            if(!flag)
                cout<<0<<endl;
            continue;
        }
        bool flag=0;
        for(int i=1;i<=lim;i++){
            if(pwb[i]==n-1){
                cout<<3<<" "<<i<<endl;
                break;
            }
            if(pwb[i]==1){
                cout<<2<<" "<<i<<endl;
                break;
            }
        }
    }
    return 0;
}