#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> mp;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(mp.find(s)==mp.end()){
            mp[s]=1;
        }else{
            mp[s]++;
        }
    }
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
        if(it->second>n/2){
            cout<< it->first;
            return 0;
        }
    }
    cout<<"uh-oh";
    return 0;
}