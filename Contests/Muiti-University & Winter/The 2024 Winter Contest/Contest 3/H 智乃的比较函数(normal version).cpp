#include<bits/stdc++.h>
using namespace std;
const int maxn=500;
int T,n,ans;
int x[maxn],y[maxn],z[maxn];
int relation[14][4]={
    {0,0,0,0},
    {0,1,1,1},
    {0,1,1,2},
    {0,1,2,1},
    {0,2,1,1},
    {0,2,2,1},
    {0,2,1,2},
    {0,1,2,2},
    {0,1,2,3},
    {0,1,3,2},
    {0,2,1,3},
    {0,2,3,1},
    {0,3,1,2},
    {0,3,2,1}
};
int main(){
    cin>>T;
    while(T--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i]>>z[i];
        for(int i=1;i<=13;i++){
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(z[j]==0&&relation[i][x[j]]>=relation[i][y[j]]){
                    cnt++;
                }
                if(z[j]==1&&relation[i][x[j]]<relation[i][y[j]]){
                    cnt++;
                }
            }
            if(cnt==n){
                ans=1;
                break;
            }
        }
        if(ans==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}