#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a;
    a.push_back(0);
    for(int i=1,cnt_0=0;i<=n;i++){
        int x;
        cin>>x;
        if(x==0){
            cnt_0++;
        }
        if(x==0){
            if(cnt_0==1){
                a.push_back(x);
            }
        }else{
            a.push_back(x);
        }
    }
    n=a.size()-1;
    if(n==1){
        if(k-1<a[1]){
            cout<<k-1<<endl;
        }else{
            cout<<k<<endl;
        }
        return ;
    }
    sort(a.begin()+1,a.end());
    int gcd=a[1+(a[1]==0)];
    for(int i=2+(a[1]==0);i<=n;i++){
        gcd=__gcd(gcd,a[i]);
    }
    for(int i=1;i<=n;i++)
        a[i]=gcd*(i-1);
    for(int i=2;i<=n;i++){
        if(k>a[i]-a[i-1]-1){
            k-=a[i]-a[i-1]-1;
        }else{
            cout<<a[i-1]+k<<endl;
            return ;
        }
    }
    cout<<a[n]+k<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}