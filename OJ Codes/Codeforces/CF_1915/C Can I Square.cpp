#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,a[maxn];
long long sum;
int main(){
    cin>>T;
    while(T--){
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i],sum+=a[i];
        if(sum<=36){
            if(sum==1||sum==4||sum==9||sum==16||sum==25||sum==36)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else{
            int low=sqrt(sum);
            for(long long i=low-1;i<=low+5;i++)
                if(i*i==sum){
                    cout<<"YES"<<endl;
                    break;
                }else if(i*i>sum){
                    cout<<"NO"<<endl;
                    break;
                }
            
        }
    }
    return 0;
}