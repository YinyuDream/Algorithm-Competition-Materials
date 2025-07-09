#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    auto query=[&](int x,int y){
        cout<<"? "<<x<<" "<<y<<endl;
        cout.flush();
        int res;
        cin>>res;
        return res;
    };
    vector<vector<int>> mapp(n+1,vector<int>(n+1));
    auto work=[&](int x){
        int now=1;
        while(true){
            int res=query(x,now);
            if(res==x){
                mapp[x][now]=mapp[now][x]=1;
                break;
            }
            now=res;
        }
    };
    for(int i=2;i<=n;i++){
        work(i);
    }
    cout<<"!"<<endl;
    cout.flush();
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
           if(mapp[i][j]==1){
               cout<<i<<" "<<j<<" ";
               cout.flush();
           }
        }
    }
    cout<<endl;
    cout.flush();
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}