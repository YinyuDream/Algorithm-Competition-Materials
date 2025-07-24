#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<set<int>> can(n+1);
    vector<vector<int>> a(n+1,vector<int>(k+1,0));
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>a[i][j];
            mp[a[i][j]]++;
        }
    }
    set<int> s;
    for(int i=1;i<=k;i++){
        s.insert(a[n][i]);
        can[n].insert(a[n][i]);
    }
    for(int i=n-1;i;i--){
        for(int j=1;j<=k;j++){
            if(s.find(a[i][j])==s.end()){
                can[i].insert(a[i][j]);
            }
        }
        for(int j=1;j<=k;j++){
            s.insert(a[i][j]);
        }
    }
    cout<<fixed<<setprecision(10);
    for(int i=1;i<=n;i++){
        set<int> st;
        for(int j=1;j<=k;j++){
            if(can[i].find(a[i][j])!=can[i].end()){
                st.insert(a[i][j]);
            }
        }
        int tot=0;
        for(auto x:st){
            tot+=mp[x];
        }
        cout<<1.0*tot/(n*k)<<endl;
    }
    return 0;
}