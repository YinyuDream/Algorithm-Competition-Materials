#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=510;
int T,n;
int a[maxn][maxn],sum[maxn];
int main(){
    sum[0]=0;
    for(int i=1;i<maxn;i++)
        sum[i]=sum[i-1]+i*(2*i-1);
    cin>>T;
    while(T--){
        cin>>n;
        cout<<sum[n]<<" "<<n*2<<endl;
        for(int i=1;i<=n*2;i++){
            if(i%2==0){
                cout<<1<<" "<<i/2<<" ";
                for(int j=n;j;j--)
                    cout<<j<<" ";
                cout<<endl;
            }else{
                cout<<2<<" "<<i/2+1<<" ";
                for(int j=n;j;j--)
                    cout<<j<<" ";
                cout<<endl;
            }
        }
    }
    return 0;
}