#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y;
bool ans;
int dis(int x,int y,int a,int b)
{
    return abs(x-a)+abs(y-b);
}
int main(){
    cin>>T;
    while(T--){
        ans=false;
        cin>>n>>m>>k;
        cin>>x>>y;
        for(int i=1,u,v;i<=k;i++){
            cin>>u>>v;
            if(dis(u,v,x,y)%2==0)ans=true;
        }
        if(ans==false)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}