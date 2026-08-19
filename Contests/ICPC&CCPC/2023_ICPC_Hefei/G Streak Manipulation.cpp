#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,m,eth;
int a[maxn],cnt[maxn],f[maxn][6],q_use[6];
queue<pair<int,int> > q_wait[6];
bool check(int len)
{
    memset(f,0x3f,sizeof f);
    memset(q_use,0x3f,sizeof q_use);
    for(int i=0;i<=eth;i++)
        while(q_wait[i].size())
            q_wait[i].pop();
    for(int i=0;i<=n;i++){
        f[i][0]=0;
        q_wait[0].push(make_pair(0,i));
    }
    for(int i=1;i<=n;i++){
        if(a[i+1]!=0)
            continue;
        for(int j=0;j<=eth;j++){
            while(q_wait[j].size()&&(q_wait[j].front().second<=i-len-(q_wait[j].front().first!=0))){
                q_use[j]=min(q_use[j],q_wait[j].front().first);
                q_wait[j].pop();
            }
        }
        for(int k=1;k<=eth;k++){
            if(q_use[k-1]!=0x3f3f3f3f){
                f[i][k]=q_use[k-1]+cnt[i]-cnt[i-len];
                q_wait[k].push(make_pair(f[i][k],i));
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(f[i][eth]<=m)
            return true;
    return false;
}
int main(){
    cin>>n>>m>>eth;
    for(int i=1;i<=n;i++){
        char ch=getchar();
        while(ch!='0'&&ch!='1')
            ch=getchar();
        a[i]=ch-'0';
        cnt[i]=cnt[i-1]+(a[i]==0);
    }
    int l=0,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<(r?r:-1)<<endl;
    return 0;
}