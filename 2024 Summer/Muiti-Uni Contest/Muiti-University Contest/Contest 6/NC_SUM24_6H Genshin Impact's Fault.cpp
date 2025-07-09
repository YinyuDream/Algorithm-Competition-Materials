#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    bool can=true;
    for(int i=0;i+9<n;i++){
        bool val=false;
        for(int j=i;j<=i+9;j++){
            if(s[j]!='3'){
                val=true;
            }
        }
        can&=val;
    }
    vector<char> vec;
    for(int i=0;i+89<n;i++){
        bool val=false;
        for(int j=i;j<=i+89;j++){
            if(s[j]=='5'||s[j]=='U'){
                val=true;
            }
        }
        can&=val;
    }
    for(int i=0;i<n;i++)
        if(s[i]=='5'||s[i]=='U')
            vec.push_back(s[i]);
    int len=vec.size();
    for(int i=0;i<len-1;i++){
        if(vec[i]!='U'&&vec[i+1]!='U'){
            can=false;
        }
    }
    if(can)cout<<"valid"<<endl;
    else cout<<"invalid"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}