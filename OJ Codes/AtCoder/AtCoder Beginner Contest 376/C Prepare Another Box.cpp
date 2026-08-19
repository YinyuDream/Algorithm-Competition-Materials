#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n-1),c;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
        cin>>b[i];
    }
    int l=0,r=1e9;
    auto check=[&](int val){
        c=b;
        c.push_back(val);
        sort(c.begin(),c.end());
        for(int i=0;i<n;i++){
            if(a[i]>c[i])return false;
        }
        return true;
    };
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    if(l==1e9+1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<l<<endl;
    return 0;
}