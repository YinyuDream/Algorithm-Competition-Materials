#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,q;
ll a[maxn],b[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(ll x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

int main(){
    cin>>T;
    while(T--){
        n=read();q=read();
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++) b[i]=a[i]*i;
        int lim=min(sqrt(n)+1,100.0); 
        vector<ll> sum1[lim][lim],sum2[lim][lim];
        for(int i=1;i<lim;i++){
            for(int j=1;j<=i;j++){
                sum1[i][j].push_back(0);
                sum2[i][j].push_back(0);
                for(int k=0;k*i+j<=n;k++){
                    sum1[i][j].push_back(sum1[i][j].back()+a[k*i+j]);
                    sum2[i][j].push_back(sum2[i][j].back()+b[k*i+j]);
                }
            }
        }
        for(int i=1;i<=q;i++){
            int s,d,k;
            cin>>s>>d>>k;
            if(d>=lim){
                ll ans=0;
                for(int j=1;j<=k;j++)
                    ans+=a[s+(j-1)*d]*j;
                write(ans);putchar(' ');
            }else{
                ll num1=sum1[d][s%d!=0?s%d:d][s/d+(s%d!=0)+k-1]-sum1[d][s%d!=0?s%d:d][s/d+(s%d!=0)-1];
                ll num2=sum2[d][s%d!=0?s%d:d][s/d+(s%d!=0)+k-1]-sum2[d][s%d!=0?s%d:d][s/d+(s%d!=0)-1];
                ll ans=(num2-(s-d)*num1)/d;
                write(ans);putchar(' ');
            }
        }
        putchar('\n');
    }
    return 0;
}