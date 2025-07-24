#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    if(n%2==1&&n<=25){
        cout<<-1<<endl;
        return;
    }
    
    if(n%2==0){
        for(int i=1;i<=n;i+=2){
            cout<<i<<" "<<i<<" ";
        }
    }else{
        vector<int> a(n+1);
        a[1]=a[10]=a[26]=1;
        for(int i=2;i<=8;i+=2)
            a[i]=a[i+1]=i;
        for(int i=11;i<=23;i+=2)
            a[i]=a[i+1]=i;
        a[25]=a[27]=25;
        swap(a[23],a[25]);
        for(int i=28;i<=n;i+=2)
            a[i]=a[i+1]=i;
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
    }
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