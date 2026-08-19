#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[60];
int main(){
    cin>>n;
    for(int i=1,u,v;i<n;i++)
        cin>>u>>v,a[u]++,a[v]++;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        if(a[i]==1)
            cnt++;
    if((n-cnt)%2==0&&n!=2)cout<<"Alice";
    else cout<<"Bob";
    return 0;
}