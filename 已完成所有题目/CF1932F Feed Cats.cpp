#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,m;
struct node{
    int l,r;
}a[maxn];
bool operator<(node u,node v)
{
    return u.l<v.l;
}
int lmn[maxn],f[maxn],cnt[maxn],f_max[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cnt[i]=f[i]=f_max[i]=0;
        for(int i=1;i<=n;i++)
            lmn[i]=i;
        for(int i=1;i<=m;i++){
            cin>>a[i].l>>a[i].r;
            cnt[a[i].l]++;
            cnt[a[i].r+1]--;
        }
        for(int i=1;i<=n;i++)
            cnt[i]+=cnt[i-1];
        sort(a+1,a+m+1);
        int mx=0;
        for(int i=1;i<=m;i++){
            if(a[i].l>mx){
                mx=a[i].l-1;
            }
            if(a[i].r>mx){
                for(int j=mx+1;j<=a[i].r;j++){
                    lmn[j]=a[i].l;
                }
                mx=a[i].r;
            }
        }
        for(int i=1;i<=n;i++){
            f[i]=cnt[i]+f_max[lmn[i]-1];
            f_max[i]=max(f_max[i-1],f[i]);
        }
        cout<<f_max[n]<<endl;
    }
    return 0;
}