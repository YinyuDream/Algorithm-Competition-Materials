#include<bits/stdc++.h>
using namespace std;
int n,m,p,x,ans;
int main(){
    cin>>n>>m>>p>>x;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
                if((x-i*j)%(2*i+2*j)==0&&(x-i*j)/(2*i+2*j)<=p&&(x-i*j)/(2*i+2*j)>=1)
                    ans++;
    cout<<ans<<endl;
    return 0;
}