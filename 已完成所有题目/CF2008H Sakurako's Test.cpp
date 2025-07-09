#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int a[maxn],b[maxn],cnt[maxn],ans[maxn],sum[maxn];
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
void solve(){
    int n,q;
    n=read();q=read();
    for(int i=1;i<=n;i++)
        cnt[i]=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        cnt[a[i]]++;
    }
    int tot=(n+1+(n%2==0))/2;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+cnt[i];
    auto check=[&](int mid,int val){
        int cur=0,num=0;
        while(cur<=n){
            num+=sum[min(cur+mid,n)]-sum[cur]+cnt[cur];
            cur+=val;
        }
        return num<tot;
    };
    for(int i=1;i<=n;i++){
        int l=0,r=i-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid,i))l=mid+1;
            else r=mid-1;
        }
        ans[i]=l;
    }
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        write(ans[x]),putchar(' ');
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}