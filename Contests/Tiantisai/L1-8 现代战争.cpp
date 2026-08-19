#include<bits/stdc++.h>
using namespace std;
struct node{
    int val,x,y;
};
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> a(n,vector<int>(m));
    vector<node> b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            b.push_back({a[i][j],i,j});
        }
    }
    sort(b.begin(),b.end(),[&](node u,node v){
        return u.val>v.val;
    });
    vector<int> ban_row(n),ban_column(m);
    int cnt=0;
    for(int i=0;i<n*m;i++){
        auto [val,x,y]=b[i];
        if(ban_row[x]||ban_column[y]){
            continue;
        }
        ban_row[x]=1,ban_column[y]=1;
        cnt++;
        if(cnt==k){
            break;
        }
    }
    int all=0;
    for(int i=0;i<n;i++){
        if(ban_row[i]){
            continue;
        }
        int tot=0;
        for(int j=0;j<m;j++){
            if(!ban_column[j]){
                cout<<a[i][j];
                tot++;
                if(tot<m-cnt){
                    cout<<" ";
                }
            }
        }
        if(++all<n-cnt)
            cout<<endl;
    }
    return 0;
}