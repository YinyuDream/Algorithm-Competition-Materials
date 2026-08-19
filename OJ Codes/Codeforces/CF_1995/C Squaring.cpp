#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int work(ll x,ll y)
{
    if(x>=y)
        swap(x,y);
    int ans=0;
    while(x<y)
    {
        x*=x;
        ans++;
    }
    return ans;
}
ll check(ll x,int y)
{
    for(int i=1;i<=y;i++)
        x*=x;
    return x;
}
int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
void write(ll x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
void solve(){
    int n=read();
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=2;i<=n;i++){
        if(a[i-1]!=1&&a[i]==1){
            cout<<-1<<endl;
            return;
        }
    }
    int bg=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=1){
            bg=i;
            break;
        }
    }
    if(bg==0){
        cout<<0<<endl;
        return;
    }
    ll ans=0;
    vector<ll> cnt(n+1,0);
    for(int i=bg;i<n;i++){
        if(a[i+1]==a[i]){
            cnt[i+1]=cnt[i];
            ans+=cnt[i+1];
        }else if(a[i+1]>a[i]){
            ll t=work(a[i],a[i+1]);
            if(check(a[i],t)!=a[i+1]){
                t--;
            }
            if(cnt[i]<=t){
                cnt[i+1]=0;
            }else{
                cnt[i+1]=cnt[i]-t;
                ans+=cnt[i]-t;
            }
            
        }else{
            ll t=work(a[i+1],a[i]);
            cnt[i+1]=t+cnt[i];
            ans+=t+cnt[i];
        }
    }
   write(ans),putchar('\n');
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}