#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),b(n+1),pos(n+1);
    int cnt=0;
    iota(a.begin(),a.end(),0);
    do{
        for(int i=1;i<=n;i++){
            b[i]=a[i]*i;
            pos[a[i]]=i;
        }
        bool is=true;
        for(int i=1;i<n;i++){
            if(b[i+1]<b[i]){
                is=false;
                break;
            }
        }
        bool can=true;
        int tot=0;
        for(int i=1;i<=n;i++){
            /*if(abs(a[i]-i)>1){
                can=false;
                break;
            }*/
            tot+=abs(a[i]-i);
        }
        if(tot<=n){
            for(int i=1;i<=n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            cnt++;
        }
    }while(next_permutation(a.begin()+1,a.end()));
    cout<<cnt<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}