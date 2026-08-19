#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string a,b,c,s;
    cin>>s;
    for(auto x:s){
        if(x>='a'&&x<='z'){
            a.push_back(x);
        }else if(x>='0'&&x<='9'){
            b.push_back(x);
        }else{
            c.push_back(x);
        }
    }
    cout<<a+b+c;
    return 0;
}