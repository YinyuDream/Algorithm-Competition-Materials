#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=131,mod=1e9+7;
int main(){
    int n,q,m,k;
    cin>>n>>q>>m>>k;
    vector<int> powp(m+2);
    powp[0]=1;
    for(int i=1;i<=m+1;i++){
        powp[i]=1ll*powp[i-1]*p%mod;
    }
    vector<string> s(n),t(q);
    vector<vector<int>> hs(n,vector<int>(m+1)),ht(q,vector<int>(m+1));
    for(int i=0;i<n;i++){
        cin>>s[i];
        s[i]=char(0)+s[i];
        for(int j=1;j<=m;j++){
            hs[i][j]=(1ll*hs[i][j-1]*p%mod+s[i][j])%mod;
        }
    }
    for(int i=0;i<q;i++){
        cin>>t[i];
        t[i]=char(0)+t[i];
        for(int j=1;j<=m;j++){
            ht[i][j]=(1ll*ht[i][j-1]*p%mod+t[i][j])%mod;
        }
    }
    auto get=[&](vector<int> &h,int l,int r){
        if(l==0) return 1ll*h[r];
        return (h[r]-1ll*h[l-1]*powp[r-l+1]%mod+mod)%mod;
    };
    for(int i=0;i<q;i++){
        int tot=0;
        for(int j=0;j<n;j++){
            int now=0;
            for(int l=1;l<=k;l++){
                int lef=1,rig=m-now;
                while(lef<=rig){
                    int mid=(lef+rig)/2;
                    if(get(hs[j],now+1,now+mid)!=get(ht[i],now+1,now+mid)){
                        rig=mid-1;
                    }else{
                        lef=mid+1;
                    }
                }
                int delta=lef;
                now+=delta;
                if(now>m){
                    break;
                }
            }
            if(now>=m||get(hs[j],now+1,m)==get(ht[i],now+1,m)){
                tot++;
            }
        }
        cout<<tot<<endl;
    }
    return 0;
}