#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    while(m--){
        string op;
        cin>>op;
        if(op=="water"){
            int l,r;
            cin>>l>>r;
            for(int i=l;i<=r;i++){
                a[i]++;
            }
        }else{
            int l,r,k;
            cin>>l>>r>>k;
            int ans=0;
            for(int i=l;i<=r;i++){
                if(a[i]>=k){
                    ans++;
                    a[i]=0;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}