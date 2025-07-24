#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        char c=getchar();
        while(c!='0'&&c!='1') c=getchar();
        a[i]=c-'0';
    }
    vector<int> b;
    for(int i=1;i<=n;i++){
        if(b.empty()||a[i]!=b.back()||(a[i]==b.back()&&a[i]!=0)){
            b.push_back(a[i]);
        }
    }
    int cnt0=0,cnt1=0;
    for(int i=0;i<b.size();i++){
        if(b[i]==0) cnt0++;
        else cnt1++;
    }
    cout<<(cnt1>cnt0?"Yes":"No")<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}