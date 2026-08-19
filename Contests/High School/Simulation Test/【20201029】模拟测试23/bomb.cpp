#pragma GCC optimize(2)
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,l,r;
int a[maxn];
int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x; 
}
bool check(int x,int pos)
{
    int l=pos,r=pos;
    while(x){
        int mx=a[r]+x,mn=a[l]-x;
        while(l>=1&&a[l]>=mn)l--;
        while(r<=n&&a[r]<=mx)r++;
        l++,r--;
        if(l==1&&r==n)return true;
        x=2*x/3;
    }
    return false;
}
int solve(int p)
{
    int _l=0,_r=a[n],num=0;
    while(_l<=_r){
        int mid=(_l+_r)/2;
        if(check(mid,p))_r=mid-1,num=mid;
        else _l=mid+1;
    }
    return num;
}
int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    l=1,r=n;
    while(l<=r){
        int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
        if(solve(lmid)<=solve(rmid))r=rmid-1;
        else l=lmid+1;
    }
    printf("%d",solve(l));
    return 0;
}
