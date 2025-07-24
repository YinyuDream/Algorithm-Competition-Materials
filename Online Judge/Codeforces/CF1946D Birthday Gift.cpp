#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,x,mx_pos;
int a[maxn],num[31];
bool check(int val,int pos)
{
    int num_a[31];
    memset(num_a,0,sizeof(num_a));
    int top=0;
    while(val){
        num_a[++top]=val%2;
        val/=2;
    }
    num_a[0]=0;
    int mx=max(top,mx_pos);
    for(int i=pos+1;i<=mx;i++){
        if(num[i]==0&&num_a[i]==1)
            return false;
    }
    if(num_a[pos]==1)
        return false;
    return true;
}
int work(int pos)
{
    if(!check(a[n],pos))
        return -1;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(check(a[i],pos)){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>x;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            a[i]^=a[i-1];
        memset(num,0,sizeof(num));
        mx_pos=0;
        while(x){
            num[++mx_pos]=x%2;
            x/=2;
        }
        num[0]=1;
        int ans=-1;
        for(int i=mx_pos;i>=0;i--){
            if(num[i]==1){
                ans=max(ans,work(i));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}