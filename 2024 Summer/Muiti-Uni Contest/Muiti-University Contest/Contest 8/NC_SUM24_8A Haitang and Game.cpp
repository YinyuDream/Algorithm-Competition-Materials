#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
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
    if(ans&1){
        cout<<"dXqwq"<<endl;
    }else{
        cout<<"Haitang"<<endl;
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