#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    double t,s;
    cin>>t>>s;
    vector<double> a(n),b(n),c(n),d(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    vector<int> ord(n);
    iota(ord.begin(),ord.end(),0);
    double ans=1e9;
    do{
        for(int i=0;i<(1<<n);i++){
            double x=0,y=0,dis=0;
            for(int j=0;j<n;j++){
                double x_s,y_s,x_e,y_e;
                if((i>>j)&1){
                    x_s=a[ord[j]],y_s=b[ord[j]];
                    x_e=c[ord[j]],y_e=d[ord[j]];
                }else{
                    x_s=c[ord[j]],y_s=d[ord[j]];
                    x_e=a[ord[j]],y_e=b[ord[j]];
                }
                dis+=hypot(x-x_s,y-y_s)/t;
                dis+=hypot(x_s-x_e,y_s-y_e)/s;
                x=x_e,y=y_e;
            }
            ans=min(ans,dis);
        }
    }while(next_permutation(ord.begin(),ord.end()));
    cout<<fixed<<setprecision(15)<<ans<<endl;
    return 0;
}