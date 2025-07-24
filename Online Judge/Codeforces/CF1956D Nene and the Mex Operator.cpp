#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=20,maxm=5e5+10;
int T,n,ans,tot;
int a[maxn],b[maxn],c[maxn],cnt_0[maxn];
int cal()
{
    int num=0;
    for(int i=1;i<=n;i++){
        if(b[i]==0){
            num+=a[i];
        }else{
            int pos=i;
            while(b[pos+1]==1)
                pos++;
            num+=(pos-i+1)*(pos-i+1);
            i=pos;
        }
    }
    return num;
}
void dfs(int x){
    if(x==n+1){
        if(ans<cal()){
            ans=cal();
            for(int i=1;i<=n;i++)
                c[i]=b[i];
        }
        return ;
    }
    b[x]=0;
    dfs(x+1);
    b[x]=1;
    dfs(x+1);
}
int ansl[maxm],ansr[maxm];
void work(int l,int r){
    if(l==r){
        return ;
    }else if(l+1==r){
        ansl[++tot]=l;
        ansr[tot]=l;
        return ;
    }
    work(l,r-1);
    ansl[++tot]=l;
    ansr[tot]=r-1;
    ansl[++tot]=l+1;
    ansr[tot]=r;
    work(l+1,r);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cnt_0[i]=cnt_0[i-1]+(a[i]==0);
    dfs(1);
    cout<<ans<<" ";
    for(int i=1;i<=n;i++){
        if(c[i]==1){
            int pos=i;
            while(c[pos+1]==1)
                pos++;
            ansl[++tot]=i;
            ansr[tot]=pos;
            if(cnt_0[pos]-cnt_0[i-1]>0){
                ansl[++tot]=i;
                ansr[tot]=pos;
            }
            work(i,pos);
            ansl[++tot]=i;
            ansr[tot]=pos;
            i=pos;
        }
    }
    cout<<tot<<endl;
    for(int i=1;i<=tot;i++)
        cout<<ansl[i]<<" "<<ansr[i]<<endl;
    return 0;
}