#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2==0){
        cout<<"No"<<endl;
        return 0;
    }
    int mid=n/2;
    if(s.substr(0,mid)!=string(mid,'1')){
        cout<<"No"<<endl;
        return 0;
    }
    if(s.substr(mid+1,mid)!=string(mid,'2')){
        cout<<"No"<<endl;
        return 0;
    }
    if(s[mid]!='/'){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    return 0;
}