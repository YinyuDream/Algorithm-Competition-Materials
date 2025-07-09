#include<bits/stdc++.h>
using namespace std;
string s,t;
int main(){
    cin>>s>>t;
    int pos=-1;
    for(auto i:s){
        pos++;
        while(pos<t.size()&&t[pos]!=i) pos++;
        cout<<pos+1<<" ";
    }
    return 0;
}