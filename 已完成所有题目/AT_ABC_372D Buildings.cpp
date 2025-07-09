#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        ans[i]=s.size();
        while(!s.empty()&&a[s.top()]<=a[i]){
            s.pop();
        }
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}