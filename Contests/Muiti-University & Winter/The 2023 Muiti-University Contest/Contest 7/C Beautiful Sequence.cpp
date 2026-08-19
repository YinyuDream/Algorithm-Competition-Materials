#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10,maxp=30;
int T,n,k,mx;
int b[maxn],sum[maxn],a1[maxp],seg_l[maxn][maxp],seg_r[maxn][maxp];
int read()
{
    int sum=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
        ch=getchar();
    while(ch>='0'&&ch<='9'){
        sum=sum*10+ch-'0';
        ch=getchar();
    }
    return sum;
}
void write(int x)
{
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
int work(int x)
{
    int cnt=0;
    while(x){
        x/=2;
        cnt++;
    }
    return cnt-1;
}
void dfs(int pos,int l,int r)
{
    if(pos==-1)return ;
    int top=l-1;
    seg_l[++top][pos]=l;
    for(int i=l;i<r;i++){
        int p=(sum[i]>>pos)&1,q=(sum[i+1]>>pos)&1;
        if(p==1&&q==0){
            if(a1[pos]==-1)
                a1[pos]=1;
            else if(a1[pos]==0)
                a1[pos]=-2;
        }
        if(p==0&&q==1){
            if(a1[pos]==-1)
                a1[pos]=0;
            else if(a1[pos]==1)
                a1[pos]=-2;
        }
        if(p!=q){
            seg_r[top][pos]=i;
            seg_l[++top][pos]=i+1;
        }
    }
    seg_r[top][pos]=r;
    for(auto i=l;i<=top;i++)
        dfs(pos-1,seg_l[i][pos],seg_r[i][pos]);
}
int main(){
    T=read();
    while(T--){
        memset(a1,-1,sizeof a1);
        mx=0;
        n=read(),k=read()-1;
        for(int i=1;i<n;i++)
            b[i]=read();
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]^b[i];
            mx=max(mx,sum[i]);
        }
        mx=work(mx);
        dfs(mx,0,n-1);
        bool flag=true;
        for(int i=0;i<maxp;i++){
            if(a1[i]==-2){
                flag=false;
            }else if(a1[i]==-1){
                a1[i]=k%2;
                k/=2;
            }
        }
        if(k>0||flag==false){
            puts("-1");
            continue;
        }
        int ans=0;
        for(int i=maxp-1;i>=0;i--)
            ans=ans*2+a1[i];
        for(int i=0;i<n;i++)
           write(ans^sum[i]),putchar(' ');
        puts("");
    }
    return 0;
}