#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,x[maxn],y[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++){
        int pos=0;
        long long mx=0;
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(mx<(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])){
                mx=(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
                pos=j;
            }
        }
        cout<<pos<<endl;
    }
    return 0;
}