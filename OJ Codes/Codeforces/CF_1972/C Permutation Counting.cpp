#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
ll k,a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=2;i<=n;i++){
            ll x=a[i]-a[i-1];
            if(x*(i-1)<k){
                k-=x*(i-1);
            }else{
                ll num=k/(i-1),rem=k%(i-1),val=a[i-1];
                for(int j=i-rem;j<i;j++)
                    a[j]=val+num+1;
                for(int j=i-rem-1;j;j--)
                    a[j]=val+num;
                k=0;
                break;
            }
        }
        if(k>0){
            ll num=k/n,rem=k%n,val=a[n];
            for(int i=n-rem+1;i<=n;i++)
                a[i]=val+num+1;
            for(int i=n-rem;i;i--)
                a[i]=val+num;
        }
        for(int i=2;i<=n;i++)
            if(a[i]>a[1]+1)
                a[i]=a[1]+1;
        ll sum=0;
        for(int i=1;i<=n;i++)
            sum+=a[i];
        cout<<sum-n+1<<endl;
    }
    return 0;
}