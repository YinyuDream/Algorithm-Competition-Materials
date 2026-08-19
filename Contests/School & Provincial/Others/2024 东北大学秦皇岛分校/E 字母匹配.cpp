#include<bits/stdc++.h>
using namespace std;
const int maxn=26;
string s;
int n,k,ans;
int low_cnt[maxn],upp_cnt[maxn];
int main(){
    cin>>n>>k>>s;
    for(auto i:s){
        if(i>='a'&&i<='z')low_cnt[i-'a']++;
        else upp_cnt[i-'A']++;
    }
    for(int i=0;i<=25;i++){
        ans+=min(upp_cnt[i],low_cnt[i]);
        int u=abs(upp_cnt[i]-low_cnt[i]);
        u/=2;
        if(k-u>=0){
            k-=u;
            ans+=u;
        }else{
            ans+=k;
            break;
        }
    }
    cout<<ans;
    return 0;
}