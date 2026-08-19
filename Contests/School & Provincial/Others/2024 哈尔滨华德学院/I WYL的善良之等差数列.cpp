#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn];
long long b[maxn];
int work(int i,int j)
{
    b[1]=a[1]-i;
    b[2]=a[2]-j;
    int d=b[2]-b[1];
    for(int i=3;i<=n;i++)
        b[i]=b[i-1]+d;
    int ans=0;
    for(int i=3;i<=n;i++){
        if(abs(a[i]-b[i])>1){
            return -1;
        }
        ans+=abs(a[i]-b[i]);
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=2){
        cout<<0;
        return 0;
    }
    int ans=1e9;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            int val=work(i,j);
            if(val!=-1){
                ans=min(ans,abs(i)+abs(j)+val);
            }
        }
    }
    if(ans==1e9)
        ans=-1;
    cout<<ans;
    return 0;
}