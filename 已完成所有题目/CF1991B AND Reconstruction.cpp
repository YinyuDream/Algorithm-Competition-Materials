#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n-1);
    for(int i=0;i<n-1;i++)
        cin>>b[i];
    for(int i=0;i<n-1;i++)
        a[i]|=b[i],a[i+1]|=b[i];
    for(int i=0;i<n-1;i++)
        if((a[i]&a[i+1])!=b[i]){
            cout<<-1<<endl;
            return;
        }
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}