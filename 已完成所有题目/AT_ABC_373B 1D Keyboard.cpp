#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int> pos(26);
    for(int i=0;i<26;i++){
        pos[s[i]-'A']=i;
    }
    int ans=0;
    for(char c='B';c<='Z';c++){
        ans+=abs(pos[c-'A']-pos[c-'A'-1]);
    }
    cout<<ans;
    return 0;
}