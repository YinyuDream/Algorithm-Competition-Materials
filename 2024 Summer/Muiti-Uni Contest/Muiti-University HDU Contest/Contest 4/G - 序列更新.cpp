#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int a[maxn],b[maxn],c[maxn],top;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(ll x)
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
void solve(){
    top=0;
    int n,q;
    n=read(),q=read();
    for(int i=0;i<n;i++)
        a[i]=read();
    for(int i=0;i<n;i++)
        b[i]=read();
    ll sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    int lim=min(5*sqrt(n),1.0*n);
    for(int i=1;i<=lim;i++){
        int k;
        k=read();
        for(int j=0;j<n;j++){
            sum-=a[j];
            a[j]=max(a[j],b[(j+k)%n]);
            sum+=a[j];
        }
        write(sum),putchar('\n');
    }
    int mn=1e9;
    set<int> s;
    for(int i=0;i<n;i++)
        mn=min(mn,a[i]);
    for(int i=0;i<n;i++)
        if(b[i]>mn)
            c[++top]=i;
    for(int i=lim+1;i<=q;i++){
        int k=read();
        for(int j=1;j<=top;j++){
            int pos=c[j]-k;
            if(pos<0)
                pos+=n;
            sum-=a[pos];
            a[pos]=max(a[pos],b[c[j]]);
            sum+=a[pos];
        }
        write(sum),putchar('\n');
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}