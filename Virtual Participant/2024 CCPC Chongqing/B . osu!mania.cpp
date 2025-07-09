#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int ppmax;
    cin>>ppmax;
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    double Acc=(30.0*a+30*b+20*c+10*d+5*e)/(0.3*(a+b+c+d+e+f));
    cout<<fixed<<setprecision(2)<<Acc<<"% ";
    int pp=round(max(0.0,(6.4*a+4.4*b-5.6*c-15.6*d-20.6*e-25.6*f)/(32*(a+b+c+d+e+f)))*5*ppmax);
    cout<<pp<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}