#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<int> a(n+1),c(n+1),pos(n+1),book(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=2;i<=n;i++){
        if(pos[i]<pos[i-1]&&!book[i]&&!book[i-1]){
            book[i]=book[i-1]=1;
            a[pos[i-1]]++;
        }
    }
    ll tot=0;
    auto add=[&](int x){
        for(int i=x;i<=n;i+=i&(-i)){
            c[i]++;
        }
    };
    auto query=[&](int x){
        int ans=0;
        for(int i=x;i;i-=i&(-i)){
            ans+=c[i];
        }
        return ans;
    };
    for(int i=n;i;i--){
        tot+=query(a[i]-1);
        add(a[i]);
    };
    cout<<tot;
    return 0;
}