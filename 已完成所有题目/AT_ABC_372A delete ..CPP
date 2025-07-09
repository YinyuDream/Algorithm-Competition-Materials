#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(auto x:s){
        if(x!='.'){
            cout<<x;
        }
    }
    return 0;
}