#include<bits/stdc++.h>
using namespace std;
constexpr int maxa=1e6;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1),book(maxa+1),can(maxa+1,1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        book[a[i]]=1;
    }
    for(int i=1;i<=maxa;i++){
        if(book[i]){
            continue;
        }
        for(int j=1;j*i<=maxa;j++){
            can[j*i]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=maxa;i++){
        if(book[i]&&can[i]){
            ans++;
        }
    }
    cout<<ans<<endl;
}