#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,cnt,ith,now,lim,num;
ll L;
struct node{
    int region,id;
    ll x,y,z;
}a[maxn];
int ans[maxn],net[maxn],pre[maxn];
bool operator<(node a,node b)
{
    if(a.region!=b.region)return a.region<b.region;
    else{
        if(a.region==1||a.region==5){
            return abs(a.y*b.x)>abs(a.x*b.y);
        }
        if(a.region==3||a.region==7){
            return abs(a.y*b.x)<abs(a.x*b.y);
        }
    }
}
bool check(ll len,node p)
{
    return p.x*p.x+p.y*p.y<=len*len;
}
int main(){
    cin>>n>>L;
    ith=1;
    for(int i=1,u,v,w;i<=n;i++){
        cin>>u>>v>>w;
        if(u==0&&v>=0&&v<=L){
            ans[i]=ith;
            num++;
            L+=w;
        }else{
            cnt++;
            a[cnt].x=u;
            a[cnt].y=v;
            a[cnt].z=w;
            a[cnt].id=i;
            if(u==0&&v>0){
                a[cnt].region=0;
            }else if(u>0&&v>0){
                a[cnt].region=1;
            }else if(u>0&&v==0){
                a[cnt].region=2;
            }else if(u>0&&v<0){
                a[cnt].region=3;
            }else if(u==0&&v<0){
                a[cnt].region=4;
            }else if(u<0&&v<0){
                a[cnt].region=5;
            }else if(u<0&&v==0){
                a[cnt].region=6;
            }else{
                a[cnt].region=7;
            } 
        }
    }
    sort(a+1,a+cnt+1);
    for(int i=1;i<=cnt;i++)
        cout<<a[i].x<<" "<<a[i].y<<endl;
    for(int i=1;i<=cnt;i++){
        net[i]=i+1;
        pre[i]=i-1;
    }
    net[cnt]=1,pre[1]=cnt,now=cnt;
    while(cnt>0){
        if(++lim>n*n)break;
        now=pre[now];
        if(check(L,a[now]))ith=++num;
        while(check(L,a[now])){
            L+=a[now].z;
            ans[a[now].id]=ith;
            net[pre[now]]=net[now];
            pre[net[now]]=pre[now];
            num++;
            cnt--;
            if(a[pre[now]].y*a[now].x!=a[pre[now]].x*a[now].y||a[pre[now]].region!=a[now].region){
                num--;
                break;
            }
            now=pre[now];
        }
    }
    for(int i=1;i<=n;i++)
        cout<<(ans[i]>0?ans[i]:-1)<<" ";
    return 0;
}