#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<long long> a(n+1),sum(n+1);
    vector<double> val(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        val[i]=a[i];
        sum[i]=sum[i-1]+a[i];
    }
    vector<int> ban(n+1);
    for(int i=0;i<=n;i++){
        ban[i]=1;
    }
    cout<<fixed<<setprecision(10);
    for(int i=1;i<=m;i++){
        int op;
        cin>>op;
        if(op==1){
            int l,r;
            cin>>l>>r;
            for(int j=l;j<r;j++){
                ban[j]=0;
            }
            int low=l,up=r-1;
            while(ban[low]==0){
                low--;
            }
            while(ban[up]==0){
                up++;
            }
            for(int j=low+1;j<=up;j++){
                val[j]=(1.0*sum[up]-sum[low])/(up-low);
            }
        }else{
            int x;
            cin>>x;
            cout<<val[x]<<endl;
        }
    }
    return 0;
}