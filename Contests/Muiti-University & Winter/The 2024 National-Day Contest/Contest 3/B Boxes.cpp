#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double C;
    cin>>n>>C;
    vector<double> w(n+1),sum(n+1);
    for(int i=1;i<=n;i++)
        cin>>w[i];
    sort(w.begin()+1,w.end());
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+w[i];
    double now=1.0/2,ans=0;
    for(int i=1;i<n;i++){
        ans+=sum[n-i]*now;
        now/=2;
    }
    cout<<fixed<<setprecision(12);
    cout<<min(C+ans,sum[n]);
    return 0;
}