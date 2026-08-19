#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,z,s;
    cin>>n>>z>>s;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    int u=0,v=0;
    for(int i=0;i<n;i++){
        if(a[i]>s){
            u=max(0,u-2);
        }else{
            u++;
        }
        if(b[i]>z){
            v=max(0,v-2);
        }else{
            v++;
        }
    }
    if(u<v){
        cout<<"sdy"<<endl;
    }else if(u>v){
        cout<<"zy"<<endl;
    }else{
        cout<<"none"<<endl;
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}