#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int m,s,c,ans;
int a[maxn];
int main(){
    cin>>m>>s>>c;
    if(c<=m){
        cout<<c<<endl;
        return 0;
    }
    for(int i=1;i<=c;i++)
        cin>>a[i];
    sort(a+1,a+c+1);
    ans=a[c]-a[1]+1;
    for(int i=1;i<c;i++)
        a[i]=a[i+1]-a[i]-1;
    sort(a+1,a+c,greater<int>());
    for(int i=1;i<m;i++)
        ans-=a[i];
    cout<<ans<<endl;
    return 0;
}