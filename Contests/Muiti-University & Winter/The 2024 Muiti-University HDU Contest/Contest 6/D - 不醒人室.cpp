#include<bits/stdc++.h>
#define l first
#define r second
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void solve(){
    int n,m;
    n=read();m=read();
    vector<pair<int,int>> a(n+1),b(m);
    a[0]={0,0};
    for(int i=1;i<=n;i++)
        a[i].l=read(),a[i].r=read();
    for(int i=0;i<m;i++)
        b[i].l=read(),b[i].r=read();
    ll mx=0;
    for(int i=1;i<=n;i++){
        int pos1=lower_bound(b.begin(),b.end(),make_pair(a[i-1].r,0))-b.begin();
        int pos2=lower_bound(b.begin(),b.end(),make_pair(a[i].l,0))-b.begin();
        for(int j=pos1;j<=min(pos2,m-1);j++){
            if(b[j].r<=a[i].l){
                mx=max(mx,b[j].r+2ll*(b[j].r-b[j].l));
            }
        }
        if(mx<a[i].r){
            puts("No");
            return;
        }
    }
    puts("Yes");
}
int main(){
    int T;
    T=read();
    while(T--){
        solve();
    }
    return 0;
}