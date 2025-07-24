#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    if(s.find('0')==string::npos){
        s.back()='0';
        cout<<1<<" "<<n<<" "<<1<<" "<<1<<endl;
        return;
    }
    string ans=s;
    int l=-1,r=-1;
    for(int i=0;i<n;i++){
        string t=s;
        for(int j=i;j>=0;j--){
            t[n-1-(i-j)]=t[j]!=t[n-1-(i-j)]?'1':'0';
            if(t[n-1-(i-j)]=='1'&&ans<=t){
                l=j,r=i;
                ans=t;
            }
        }
    }
    cout<<l+1<<" "<<r+1<<" "<<1<<" "<<n<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}