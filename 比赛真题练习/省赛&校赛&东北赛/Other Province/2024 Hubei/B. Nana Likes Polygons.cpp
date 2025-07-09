#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e2+10;
int T,n;
int x[maxn],y[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        if(n<=2){
            cout<<-1<<endl;
            continue;
        }
        ll ans=1e18;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=j+1;k<=n;k++){
                    int x_1=x[j]-x[i],x_2=x[k]-x[i],y_1=y[j]-y[i],y_2=y[k]-y[i];
                    ll S=abs(x_1*y_2-x_2*y_1);
                    if(S==0)continue;
                    ans=min(ans,S);
                }
            }
        }
        if(ans==1e18){
            cout<<-1<<endl;
        }else{
            cout<<1.0*ans/2<<endl;
        }
    }
    return 0;
}