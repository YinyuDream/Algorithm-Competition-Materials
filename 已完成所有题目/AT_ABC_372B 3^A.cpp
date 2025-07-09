#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin>>m;
    vector<int> pw3(11);
    pw3[0]=1;
    for(int i=1;i<11;i++){
        pw3[i]=pw3[i-1]*3;
    }
    vector<int> ans;
    for(int i=10;i>=0;i--){
        while(m>=pw3[i]){
            m-=pw3[i];
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}