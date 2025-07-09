#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<int> a(n);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s.substr(i,4)=="1100"){
            a[i]=1;
            cnt++;
        }
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int pos,val;
        cin>>pos>>val;
        pos--;
        for(int i=max(0,pos-3);i<=min(n-1,pos);i++){
            if(a[i]==1){
                cnt--;
            }
        }
        s[pos]=val+'0';
        for(int i=max(0,pos-3);i<=min(n-1,pos);i++){
            if(s.substr(i,4)=="1100"){
                a[i]=1;
                cnt++;
            }
            else{
                a[i]=0;
            }
        }
        if(cnt>0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}