#include<bits/stdc++.h>
using namespace std;
int val[26],cnt[26];
int main(){
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        cnt[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        cin>>val[i];
    }
    long long ans=0;
    for(int i=0;i<26;i++){
        cout<<cnt[i]<<" ";
        ans+=1ll*val[i]*cnt[i];
    }
    cout<<endl;
    cout<<ans;
    return 0;
}