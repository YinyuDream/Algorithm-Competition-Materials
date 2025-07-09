#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    vector<int> a(6);
    while(n--){
        vector<int> v(6);
        for(int i=1;i<=5;i++){
            cin>>v[i];
        }
        sort(v.begin()+1,v.end());
        for(int i=5;i;i--){
            if(x>=v[i]){
                x-=v[i];
                a[v[i]]++;
                break;
            }
        }
    }
    for(int i=1;i<=5;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<x;
}