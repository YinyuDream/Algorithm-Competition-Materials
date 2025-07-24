#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=17;
int T,n;
map<string,int> mp1,mp2;
int cnt1,cnt2,s[maxn],t[maxn];
int f[1<<maxn][maxn];
bool can(int x,int y){
    return s[x]==s[y]||t[x]==t[y];
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            string str;
            cin>>str;
            if(mp1.find(str)==mp1.end()) 
                mp1[str]=++cnt1;
            s[i]=mp1[str];
            cin>>str;
            if(mp2.find(str)==mp2.end()) 
                mp2[str]=++cnt2;
            t[i]=mp2[str];
        }
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for(int i=1;i<=n;i++)
            f[1<<(i-1)][i]=1;
        for(int i=1;i<(1<<n);i++)
            if(__builtin_popcount(i)>1)
                for(int j=1;j<=n;j++)
                    if(i&(1<<(j-1)))
                        for(int k=1;k<=n;k++)
                            if((i&(1<<(k-1)))&&can(j,k))
                                f[i][j]|=f[i^(1<<(j-1))][k];
        int ans=0;
        for(int i=0;i<(1<<n);i++)
            for(int j=1;j<=n;j++)
                if(1<<(j-1)&i&&f[i][j])
                    ans=max(ans,__builtin_popcount(i));
        cout<<n-ans<<endl;
    }
    return 0;
}