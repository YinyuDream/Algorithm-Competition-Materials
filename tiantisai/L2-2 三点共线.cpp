#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
};
bool operator<(node u, node v){
    if(u.y!=v.y){
        return u.y<v.y;
    }
    return u.x<v.x;
}
int main(){
    int n;
    cin>>n;
    vector<int> a,b;
    set<int> st;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(y==0){
            a.push_back(x);
        }
        if(y==1){
            b.push_back(x);
        }
        if(y==2){
            st.insert(x);
        }
    }
    vector<node> ans;
    set<node> have;
    for(auto x:b){
        for(auto y:a){
            int z=2*x-y;
            if(st.find(z)!=st.end()){
                node res;
                res.y=x,res.x=y,res.z=z;
                if(have.find(res)==have.end()){
                    ans.push_back(res);
                    have.insert(res);
                }
            }
        }
    }
    if(ans.empty()){
        cout<<-1;
        return 0;
    }
    sort(ans.begin(),ans.end());
    for(auto [x,y,z]:ans){
        cout<<"["<<x<<", "<<0<<"] ";
        cout<<"["<<y<<", "<<1<<"] ";
        cout<<"["<<z<<", "<<2<<"]\n";
    }
    return 0;
}