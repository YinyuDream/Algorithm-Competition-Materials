#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    vector<int> book(n+1),bk(n+1);
    int cnt=0,tot=0;
    for(int i=1,now=0;i<=m;i++){
        bk[b[i]]++;
        if(bk[b[i]]==1){
            tot++;
        }
        while(book[b[i]]==0){
            book[a[++now]]++;
            if(book[a[now]]==1){
                cnt++;
            }
        }
        if(cnt>tot){
            cout<<"TIDAK"<<endl;
            return;
        }
    }
    cout<<"YA"<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}