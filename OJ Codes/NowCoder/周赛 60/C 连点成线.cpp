#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> x(n+1),y(n+1);
    for(int i=1;i<=m;i++){
        int _x,_y;
        cin>>_x>>_y;
        x[_x].push_back(_y);
        y[_y].push_back(_x);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(x[i].size()){
            sort(x[i].begin(),x[i].end());
            ans=max(ans,x[i].back()-x[i].front());
        }
        if(y[i].size()){
            sort(y[i].begin(),y[i].end());
            ans=max(ans,y[i].back()-y[i].front());
        }
    }
    cout<<ans;
    return 0;
}