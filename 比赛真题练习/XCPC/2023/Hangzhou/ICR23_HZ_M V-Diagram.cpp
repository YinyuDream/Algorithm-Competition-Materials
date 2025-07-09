#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,pos;
int a[maxn];
long long sum[maxn];
double avg;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=a[i]+sum[i-1];
        }
        for(int i=2;i<n;i++){
            if(a[i]<a[i+1]&&a[i]<a[i-1]){
                pos=i;
                break;
            }
        }
        avg=max(max(1.0*sum[n]/n,(1.0*sum[n]-sum[pos-2])/(n-pos+2)),1.0*sum[pos+1]/(pos+1));
        printf("%.20f\n",avg);
    }
    return 0;
}