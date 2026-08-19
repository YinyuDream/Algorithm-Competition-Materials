#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int sz;
int a[maxn],b[maxn];
vector<int>pos[maxn];
struct query{
    int l,r,val;
}q[maxn];
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
bool cmp(query a,query b)
{
	if(a.l/sz==b.l/sz)return a.r<b.r;
	else return a.l/sz<b.l/sz;
}
int cnt[maxn];
void work()
{
    int n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        pos[a[i]].push_back(i);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int tot=unique(b+1,b+n+1)-b-1,cnt_q=0;
    for(int i=1;i<=tot;i++){
        if(pos[b[i]].size()){
            if(pos[b[i]].front()>=2){
                q[++cnt_q].l=1;
                q[cnt_q].r=pos[b[i]][0]-1;
                q[cnt_q].val=b[i-1]+1;
            }
            if(pos[b[i]].back()<=n-1){
                q[++cnt_q].l=pos[b[i]][pos[b[i]].size()-1]+1;
                q[cnt_q].r=n;
                q[cnt_q].val=b[i-1]+1;
            }
            if(pos[b[i]].size()>=2){
                for(unsigned int j=1;j<pos[b[i]].size();j++){
                    if(pos[b[i]][j]-pos[b[i]][j-1]>=2){
                        q[++cnt_q].l=pos[b[i]][j-1]+1;
                        q[cnt_q].r=pos[b[i]][j]-1;
                        q[cnt_q].val=b[i-1]+1;
                    }
                }
            }

        }
    }
    sz=sqrt(n);
    sort(q+1,q+cnt_q+1,cmp);
    int l=0,r=0,sum=0,ans=0;
    for(int i=1;i<=tot;i++)
        cnt[b[i]]++;
    for(int i=1;i<=m+1;i++){
        if(cnt[i]==0){
            ans=tot-i;
            break;
        }
    }
    for(int i=1;i<=tot;i++)
        cnt[b[i]]=0;
    for(int i=1;i<=cnt_q;i++){
        while(l<q[i].l)sum-=!--cnt[a[l++]];
		while(l>q[i].l)sum+=!cnt[a[--l]]++;
		while(r<q[i].r)sum+=!cnt[a[++r]]++;
		while(r>q[i].r)sum-=!--cnt[a[r--]];
        ans=max(ans,sum-q[i].val);
    }
    cout<<ans<<endl;
    for(int i=1;i<=tot;i++){
        cnt[b[i]]=0;
        pos[b[i]].clear();
    }
    cnt_q=0;
}
int main(){
    int T=read();
    while(T--){
        work();
    }
    return 0;
}