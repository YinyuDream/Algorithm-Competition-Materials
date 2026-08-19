#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    double ans=0;
    cout<<fixed<<setprecision(2);
    if(n==1){
        cout<<ans<<endl;
    }else{
        ans+=(a[0]+a[1])/2.0;
        for(int i=2;i<n;i++){
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}