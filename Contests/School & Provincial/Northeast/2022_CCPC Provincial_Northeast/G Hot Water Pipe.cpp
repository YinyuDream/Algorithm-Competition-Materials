#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m;
ll Tmin,Tmax,lst;
int a[maxn];
struct node{
    ll T,t;
    int sz;
};
deque<node>q;
int temperature(int iT,ll it,ll t)
{
    iT-=t-it+Tmin;
    iT=iT%(Tmax-Tmin+1);
    iT=(iT+(Tmax-Tmin+1))%(Tmax-Tmin+1);
    return iT+Tmin;
}
int read()
{
    int num=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){
        num=num*10+ch-'0';
        ch=getchar();
    }
    return num;
}
int main(){
    n=read(),m=read(),Tmin=read(),Tmax=read();
    for(int i=1;i<=n;i++)
        q.push_front({read(),0,1});
    for(int i=1;i<=m;i++){
        int k;
        ll t,ans=0;
        t=read(),k=read();
        t+=lst;
        lst=t;
        if(k>=n){
            while(q.size()){
                node u=q.front();
                q.pop_front();
                ans+=1ll*u.sz*temperature(u.T,u.t,t);
                k-=u.sz;
            }
            ans+=1ll*k*Tmax;
            q.push_back({Tmax,t,n});
        }else{
            q.push_back({Tmax,t,k});
            while(k-q.front().sz>=0){
                node u=q.front();
                q.pop_front();
                ans+=1ll*u.sz*temperature(u.T,u.t,t);
                k-=u.sz;
            }
            node u=q.front();
            ans+=1ll*k*temperature(u.T,u.t,t);
            q[0].sz-=k;
        }
        printf("%lld\n",ans);
    }
    return 0;
}