#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    vector<pair<int,int>> u1,u2;
    u1.push_back({a,b}),u1.push_back({-a,b}),u1.push_back({a,-b}),u1.push_back({-a,-b});
    u1.push_back({b,a}),u1.push_back({-b,a}),u1.push_back({b,-a}),u1.push_back({-b,-a});
    u2.push_back({c,d}),u2.push_back({-c,d}),u2.push_back({c,-d}),u2.push_back({-c,-d});
    u2.push_back({d,c}),u2.push_back({-d,c}),u2.push_back({d,-c}),u2.push_back({-d,-c});
    vector<vector<int>> book1(n+1,vector<int>(n+1,0));
    vector<vector<int>> book2(n+1,vector<int>(n+1,0));
    book1[1][1]=book2[1][1]=1;
    queue<tuple<int,int,int>> q;
    q.push({1,1,1});
    q.push({1,1,2});
    while(!q.empty()){
        auto [x,y,z]=q.front();
        q.pop();
        if(z==1){
            for(auto [dx,dy]:u2){
                int nx=x+dx,ny=y+dy;
                if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&book2[nx][ny]==0){
                    book2[nx][ny]=1;
                    q.push({nx,ny,2});
                }
            }
        }
        else{
            for(auto [dx,dy]:u1){
                int nx=x+dx,ny=y+dy;
                if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&book1[nx][ny]==0){
                    book1[nx][ny]=1;
                    q.push({nx,ny,1});
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=book1[i][j]|book2[i][j];
        }
    }
    cout<<ans<<endl;
}
int main(){
    solve();
    return 0;
}