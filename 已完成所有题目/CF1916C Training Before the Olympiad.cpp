#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],cnt_o[maxn],cnt_e[maxn];
long long sum[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i],cnt_o[i]=cnt_e[i]=sum[i]=0;
            if(a[i]%2==0){
                cnt_e[i]++;
            }else{
                cnt_o[i]++;
            }
            cnt_e[i]+=cnt_e[i-1];
            cnt_o[i]+=cnt_o[i-1];
            sum[i]=sum[i-1]+a[i];
        }
        cout<<a[1]<<" ";
        for(int i=2;i<=n;i++){
            cout<<sum[i]-cnt_o[i]/3-(cnt_o[i]%3==1)<<" ";
        }
        cout<<endl;
    }
    return 0;
}