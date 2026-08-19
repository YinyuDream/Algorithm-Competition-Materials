#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,x,y;
int a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>x>>y;
        for(int i=1;i<=x;i++) cin>>a[i];
        sort(a+1,a+x+1);
        int num=a[1];
        for(int i=1;i<=x;i++)
            a[i]-=num-1;
        int ans=x-2;
        for(int i=1;i<x;i++)
            if(a[i+1]-a[i]==2) ans++;
        if(a[x]==n-1&&a[1]==1) ans++;
        cout<<ans<<endl;
    }
    return 0;
}