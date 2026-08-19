#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int l=2,r=2;
    set<pair<int,int>> st;
    auto check=[&](int x,int y){
        return st.find({x,y})!=st.end();
    };
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>y>>x;
        st.insert({x,y-1});
        if(x==0){
            l=r=1;
        }
    }
    for(auto [x,y]:st){
        if(check(x,y^1)){
            if(x<0){
                l=0;
            }else{
                r=0;
            }
        }else{
            bool p=check(x-1,y^1),q=check(x+1,y^1);
            if(p){
                if(x<=0){
                    l=0;
                }else{
                    r=0;
                }
            }
            if(q){
                if(x>=0){
                    r=0;
                }else{
                    l=0;
                }
            }
            if(!p&&!q){
                if(x<0){
                    l=min(l,1);
                }
                if(x>0){
                    r=min(r,1);
                }
            }
        }
    }
    cout<<min(l+r,3-check(0,1)-check(-1,0)-check(1,0))<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}