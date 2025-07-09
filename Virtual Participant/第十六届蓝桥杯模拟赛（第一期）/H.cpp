#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    cout<<stoi(s.substr(0,s.find('-')))-stoi(s.substr(s.find('-')+1))<<endl;
    return 0;
}