#include<iostream>  
#include<cstdio>  
#include<cstring>  
#define ll long long  
#define N 100005  
using namespace std;  
  
int n,cnt,tot,dfsclk,pos[N],fst[N],pnt[N<<1],len[N<<1],nxt[N<<1],a[N],b[N],c[N],fa[N];  
ll f[N],u1[N],u2[N],v1[N],v2[N],ans; bool ok[N];  
void add(int x,int y,int z){  
    pnt[++tot]=y; len[tot]=z; nxt[tot]=fst[x]; fst[x]=tot;  
}  
void dfs(int x){  
    pos[x]=++dfsclk; int p;  
    for (p=fst[x]; p; p=nxt[p]){  
        int y=pnt[p];  
        if (y!=fa[x]){  
            if (!pos[y]){ fa[y]=x; c[y]=len[p]; dfs(y); }  
            else if (pos[y]>pos[x]){  
                for (; y!=x; y=fa[y]){  
                    ok[y]=0;  
                    a[++cnt]=y; b[cnt]=c[y];  
                }  
                ok[x]=0;  
                a[++cnt]=x; b[cnt]=len[p];  
            }  
        }  
    }  
}  
void dp(int x,int last){  
    int p;  
    for (p=fst[x]; p; p=nxt[p]){  
        int y=pnt[p];  
        if (ok[y] && y!=last){  
            dp(y,x);  
            ans=max(ans,f[x]+f[y]+len[p]);  
            f[x]=max(f[x],f[y]+len[p]);  
        }  
    }  
}  
int main(){  
    scanf("%d",&n); int i,x,y,z;  
    memset(ok,1,sizeof(ok));  
    for (i=1; i<=n; i++){  
        scanf("%d%d%d",&x,&y,&z);  
        add(x,y,z); add(y,x,z);  
    }  
    dfs(1);  
    ll sum=0,mx=0;  
    for (i=1; i<=cnt; i++) dp(a[i],0);  
    for (i=1; i<=cnt; i++){  
        sum+=b[i-1]; u1[i]=max(u1[i-1],f[a[i]]+sum);  
        v1[i]=max(v1[i-1],f[a[i]]+sum+mx);  
        mx=max(mx,f[a[i]]-sum);  
    }  
    ll tmp=b[cnt]; sum=mx=b[cnt]=0;  
    for (i=cnt; i; i--){  
        sum+=b[i]; u2[i]=max(u2[i+1],f[a[i]]+sum);  
        v2[i]=max(v2[i+1],f[a[i]]+sum+mx);  
        mx=max(mx,f[a[i]]-sum);  
    }  
    ll mn=v1[cnt];  
    for (i=1; i<cnt; i++) mn=min(mn,max(max(v1[i],v2[i+1]),u1[i]+u2[i+1]+tmp));  
    ans=max(ans,mn);  
    printf("%lld.%d\n",ans>>1,(ans&1)?5:0);  
    return 0;  
}  
/*显然题中的图就是一个环基树。另外对于最优点，必然存在两个点与该点距离相等且都是最远点，考虑这两个点与最优点所构成的链。
       1.如果这条链在环外面的树上，那么显然一定是树的直径（另一方面，对于任意环外面的树上的直径，答案必然>直径的一半）；
       2.如果这条链一部分在环上，那么必然存在换上的两个点x,y，这条链由：x对应树中x的最长链，环上x->y最短路，y对应树中y的最长链组成。
       无论哪种情况，显然都可以在环上去掉一条边而最优点到最远点的距离不变；因此不妨在换上去掉一条边，然后求此时树的直径然后除以2就是答案。
	   由上面两种情况，第1种情况可以单独处理；第2种直接递推即可。
	   然后求第一种的最大值ans1，第二种枚举断哪一条边取最小值ans2，答案即max(ans1,ans2)/2。*/

/*这是一个环套树 
首先，要求距离最远的点最近，那么必然有至少2点到这个点距离相等（否则可以向距离最远的点移动），只要找最长的链，长度/2即答案 
先求出每棵树的直径，树内的点到根的最远距离，最长的链有可能是某棵树的直径，否则就经过环，然后考虑从环上断开一条边，因为这条链不可能经过整个环，所以不断链上的边对答案是无影响的，枚举断开某一条边算最长链，取所有断边方案的最小值 
断开某一条边的答案可以DP求 
给环上的点标号1~k 
设pre1[i]表示1~i的树上的所有点到1的最大值，
suf1[i]表示i~k的树上的所有点到k的最大值 
设pre2[i]表示1~i的任意两棵树之间组成的最长链的最大值，
suf2[i]类似，表示的是i~k 
这个可以正着扫一遍倒着扫一遍求粗来 
然后断开i~i+1的边就是 
max(pre1[i]+suf1[i+1]+（1和k之间的边长）,pre2[i],suf2[i+1])*/ 
