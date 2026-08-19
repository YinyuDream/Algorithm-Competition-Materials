#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,p1=1e9+9,p2=1e9+7;
int n,m,q;
char s1[maxn],s2[maxn];
long long hash1_7[maxn],hash2_7[maxn],pow_7[maxn];
long long hash1_9[maxn],hash2_9[maxn],pow_9[maxn];
long long query_7(int l,int r,int op)
{
    long long num=pow_7[r-l+1];
    long long ans=0;
    if(op==1)
        ans=hash1_7[r]-hash1_7[l-1]*num;
    else
        ans=hash2_7[r]-hash2_7[l-1]*num;
    ans%=p1;
    if(ans<0)
        ans=(ans+p1)%p1;
    return ans;
}
long long query_9(int l,int r,int op)
{
    long long num=pow_9[r-l+1];
    long long ans=0;
    if(op==1)
        ans=hash1_9[r]-hash1_9[l-1]*num;
    else
        ans=hash2_9[r]-hash2_9[l-1]*num;
    ans%=p2;
    if(ans<0)
        ans=(ans+p2)%p2;
    return ans;
}
bool check(int l1,int l2,int dis)
{
    if(dis==0)
        return true;
    else
        return query_7(l1,l1+dis-1,1)==query_7(l2,l2+dis-1,2)&&query_9(l1,l1+dis-1,1)==query_9(l2,l2+dis-1,2);
}
int query(int l1,int r1,int l2,int r2)
{
    int l=0,r=r1-l1+1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(l1,l2,mid))l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main(){
    pow_7[0]=pow_9[0]=1;
    cin>>n>>m>>q>>(s1+1)>>(s2+1);
    for(int i=1;i<=n;i++)
        hash1_7[i]=(hash1_7[i-1]*131+(s1[i]-'a'))%p1;
    for(int i=1;i<=m;i++)
        hash2_7[i]=(hash2_7[i-1]*131+(s2[i]-'a'))%p1;
    for(int i=1;i<=n;i++)
        hash1_9[i]=(hash1_9[i-1]*131+(s1[i]-'a'))%p2;
    for(int i=1;i<=m;i++)
        hash2_9[i]=(hash2_9[i-1]*131+(s2[i]-'a'))%p2;
    for(int i=1;i<=max(n,m);i++)
        pow_7[i]=pow_7[i-1]*131%p1;
    for(int i=1;i<=max(n,m);i++)
        pow_9[i]=pow_9[i-1]*131%p2;
    for(int i=1;i<=q;i++){
        int l1,l2,r1,r2;
        cin>>l1>>r1>>l2>>r2;
        int dis=query(l1,r1,l2,r2);
        if(dis==r1-l1+1){
            cout<<'='<<endl;
        }else{
            char u=s1[l1+dis],v=s2[l2+dis];
            if(u>v)cout<<'>'<<endl;
            else cout<<'<'<<endl;
        }
    }
    return 0;
}