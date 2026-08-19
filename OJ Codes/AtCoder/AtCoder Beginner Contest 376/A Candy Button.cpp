#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin>>n>>c;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0,lst=-1e9;
    for(int i=0;i<n;i++){
        if(a[i]-lst>=c){
            ans++;
            lst=a[i];
        }
    }
    cout<<ans;
    return 0;
}