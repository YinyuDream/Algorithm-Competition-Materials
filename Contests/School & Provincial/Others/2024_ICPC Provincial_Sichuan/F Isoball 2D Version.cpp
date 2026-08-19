#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    double x,y,r,vx,vy;
    double lx,ly,rx,ry;
    cin>>x>>y>>r>>vx>>vy;
    cin>>lx>>ly>>rx>>ry;
    double mint=0,maxt=1e9;
    if(vx==0){
        if(x-r<lx||x+r>rx||2*r>ry-ly){
            cout<<"No"<<endl;
            return;
        }
    }
    if(vy==0){
        if(y-r<ly||y+r>ry||2*r>rx-lx){
            cout<<"No"<<endl;
            return;
        }
    }
    if(vx>0){
        mint=max(mint,(lx+r-x)/vx);
        maxt=min(maxt,(rx-r-x)/vx);
    }
    if(vx<0){
        mint=max(mint,(rx-r-x)/vx);
        maxt=min(maxt,(lx+r-x)/vx);
    }
    if(vy>0){
        mint=max(mint,(ly+r-y)/vy);
        maxt=min(maxt,(ry-r-y)/vy);
    }
    if(vy<0){
        mint=max(mint,(ry-r-y)/vy);
        maxt=min(maxt,(ly+r-y)/vy);
    }
    if(mint>maxt)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}