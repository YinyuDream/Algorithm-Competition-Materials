#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<vector<int>> a(k+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            cin>>a[j][i];
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            a[i][j]|=a[i][j-1];
        }
    }
    while(q--){
        int m;
        cin>>m;
        int low=1,up=n;
        for(int i=1;i<=m;i++){
            int r,c;
            char o;
            cin>>r>>o>>c;
            if(o=='>'){
                int pos=upper_bound(a[r].begin()+1,a[r].end(),c)-a[r].begin();
                low=max(low,pos);
            }else{
                int pos=lower_bound(a[r].begin()+1,a[r].end(),c)-a[r].begin()-1;
                up=min(up,pos);
            }
        }
        if(low>up||low>n||up<1){
            cout<<-1<<endl;
        }else{
            cout<<low<<endl;
        }
    }
    return 0;
}