#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,flag;
ll a[maxn],b[maxn],minx[maxn],up,nup;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            minx[i]=0x3f3f3f3f3f3f3f3fll;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(n%2==0||n==1){
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            b[i]=a[i]-a[i-1];
            minx[i]=min(minx[i-1],b[i]);
        } 
        if(b[n]<0){
            cout<<"NO"<<endl;
            continue;
        }
        flag=up=0;
        for(int i=n-1;i;i-=2){
            nup=up+(b[i+1]+up)/i;
            if(b[i]+nup<0||b[i+1]+up<0){
                flag=0;
                break;
            }else if(minx[i]+nup>=0){
                flag=1;
                break;
            }
            up=nup;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}