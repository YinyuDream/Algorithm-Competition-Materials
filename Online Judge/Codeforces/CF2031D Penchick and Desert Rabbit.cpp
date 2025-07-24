#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
struct node{
    int to,next;
};
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),mx(n+1),fa(n+1),mx_val(n+1);
    vector<vector<int>> pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]].push_back(i);
        mx_val[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        if(pos[i].empty()){
            mx[i]=mx[i-1];
            continue;
        }
        mx[i]=max(mx[i-1],*max_element(pos[i].begin(),pos[i].end()));
    }
    vector<node> edge(2*n+1);
    vector<int> head(n+1);
    set<pair<int,int>> st;
    iota(fa.begin(),fa.end(),0);
    function<int(int)> find=[&](int x){
        return x==fa[x]?x:fa[x]=find(fa[x]);
    };
    auto merge=[&](int x,int y){
        x=find(x);
        y=find(y);
        if(x!=y){
            fa[x]=y;
            mx_val[y]=max(mx_val[x],mx_val[y]);
        }
    };
    st.insert({-a[1],1});
    for(int i=2;i<=n;i++){
        auto [x,y]=*st.begin();
        x=-x;
        if(x>a[i]){
            merge(i,y);
        }
        st.insert({-a[i],i});
    }
    for(int i=1;i<=n;i++){
        for(auto j:pos[i]){
            if(mx[i-1]>j){
                merge(j,mx[i-1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<mx_val[find(i)]<<" ";
    }
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}