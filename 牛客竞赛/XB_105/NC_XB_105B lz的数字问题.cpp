#include<bits/stdc++.h>
using namespace std;
bool areEqual(const string& a, const string& b) {
    size_t dot_pos_a=a.find('.');
    size_t dot_pos_b=b.find('.');
    if(dot_pos_a==string::npos)dot_pos_a=a.length();
    if(dot_pos_b==string::npos)dot_pos_b=b.length();
    if(a.substr(0,dot_pos_a)!=b.substr(0,dot_pos_b)){
        return false;
    }
    string frac_part_a=dot_pos_a==a.length()?string(6,'0'):a.substr(dot_pos_a+1,6);
    string frac_part_b=dot_pos_b==b.length()?string(6,'0'):b.substr(dot_pos_b+1,6);
    frac_part_a.resize(6,'0');
    frac_part_b.resize(6,'0');
    return frac_part_a==frac_part_b;
}
int main() {
    string a,b;
    cin>>a>>b;
    if(areEqual(a,b)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    return 0;
}
