#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> book(a.back()+1,0);
    for(auto i:a)
        book[i]=1;
    int ans=0;
    for(int i=1;i<a.back();i++){
        if(book[i])continue;
        int gcd=0;
        for(int j=1;j*i<=a.back();j++){
            if(book[j*i]){
                if(gcd==0){
                    gcd=j*i;
                }else{
                    gcd=__gcd(gcd,j*i);
                }
            }
        }
        if(gcd==i){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}