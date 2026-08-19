#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,D,ans;
int s[maxn],p[maxn],sum[maxn];
int main(){
    cin>>n>>D;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        cin>>p[i];
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    swap(s[D],s[1]);
    sort(s+2,s+n+1,[](int a, int b){return a>b;});
    sort(p+2,p+n+1,[](int a, int b){return a>b;});
    int pos=n+1;
    for(int i=2;i<=pos;i++)
        if(s[i]<=s[1]+p[1]&&p[i]<=s[1]+p[1]){
            pos=i;
            break;
        }
    if(pos!=n+1)
        sort(p+pos,p+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=s[i]+p[i];
    sort(sum+2,sum+n+1);
    ans=1;
    for(int i=n;i>=2;i--)
        if(sum[i]>sum[1])
            ans++;
    cout<<ans;
    return 0;
}