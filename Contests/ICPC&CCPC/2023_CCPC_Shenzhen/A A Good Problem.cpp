#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    vector<pii> ans;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    auto work=[&](int op,int x){
        if(op==1){
            for(int i=0;i<n;i++){
                if(a[i]==x){
                    a[i]++;
                }
            }
        }else{
            a[x]++;
        }
    };
    function<void(int,int)> solve=[&](int l,int r){
        if(l>=r){
            return;
        }
        int mid=(l+r)/2;
        for(int i=0;i<n;i++){
            if(b[i]<=r&&b[i]>mid){
                work(2,i);
                ans.push_back({2,i+1});
            }
        }
        for(int i=l+1;i<=mid;i++){
            work(1,i);
            ans.push_back({1,i});
        }
        solve(l,mid);
        solve(mid+1,r);
    };
    solve(0,n);
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans){
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}