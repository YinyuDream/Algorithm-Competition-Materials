#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e6+10,p=998244353;
int a,b,c,d,x,y;
int prime[maxn],not_prime[maxn],cnt;
void init()
{
    for(int i=2;i<maxn;i++){
        if(!not_prime[i])
            prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<maxn;j++){
            not_prime[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
}
int fac[maxn],cnt_x[maxn],cnt_y[maxn],top;
int ksm(int a,ll b)
{
    if(b==0)return 1;
    int ans=ksm(a,b/2);
    ans=1ll*ans*ans%p;
    if(b&1)ans=1ll*ans*a%p;
    return ans;
}
int work(int pos)
{
    int num=fac[pos],t1=cnt_x[pos],t2=cnt_y[pos];
    ll tot=0;
    for(int x=a;x<=b;x++){
        int l=c,r=d;
        l=max(l,x*t1/t2+((x*t1)%t2!=0));
        if(r-l+1>0){
            tot+=1ll*x*t1*(r-l+1);
            tot%=(p-1);
        }
    }
    for(int y=c;y<=d;y++){
        int l=a,r=b;
        l=max(l,y*t2/t1+1);
        if(r-l+1>0){
            tot+=1ll*y*t2*(r-l+1);
            tot%=(p-1);
        }
    }
    return ksm(num,tot+p-1);
}
int main(){
    cin>>a>>b>>c>>d>>x>>y;
    init();
    int val=__gcd(x,y);
    if(val==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=cnt;i++){
        if(val%prime[i]==0){
            top++;
            fac[top]=prime[i];
            while(x%prime[i]==0){
                cnt_x[top]++;
                x/=prime[i];
            }
            while(y%prime[i]==0){
                cnt_y[top]++;
                y/=prime[i];
            }
        }
    }
    int ans=1;
    for(int i=1;i<=top;i++)
        ans=1ll*ans*work(i)%p;
    cout<<ans;
    return 0;
}