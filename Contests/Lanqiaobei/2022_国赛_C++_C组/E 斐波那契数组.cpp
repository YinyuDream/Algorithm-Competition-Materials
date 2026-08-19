#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,ans,mx;
int a[maxn],feb[41];
int solve(int num)
{
    int pos=0,val=0;
    feb[1]=feb[2]=num;
    for(int i=3;i<=40;i++){
        feb[i]=feb[i-1]+feb[i-2];
        if(feb[i]>mx){
            pos=i;
            break;
        }
    }
    if(feb[1]>mx)pos=0;
    for(int i=1;i<=min(pos,n);i++)
        if(feb[i]!=a[i])
            val++;
    return val+max(n-pos,0);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i],mx=max(mx,a[i]);
    ans=n;
    for(int i=1;i<=mx;i++)
        ans=min(ans,solve(i));
    cout<<ans;
    return 0;
}