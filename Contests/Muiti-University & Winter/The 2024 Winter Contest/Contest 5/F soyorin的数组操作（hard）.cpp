#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,flag;
ll a[maxn],b[maxn],minx[maxn],up,nup,cnt;
int main(){
    cin>>T;
    while(T--){
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            minx[i]=0x3f3f3f3f3f3f3f3fll;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        
        for(int i=1;i<=n;i++){
            b[i]=a[i]-a[i-1];
            minx[i]=min(minx[i-1],b[i]);
        }
        if(n%2==0){
            cout<<max(-minx[n],0ll)<<endl;
            continue;
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        if(b[n]<0){
            cout<<-1<<endl;
            continue;
        }
        flag=up=cnt=0;
        for(int i=n-1;i;i-=2){
            nup=up+(b[i+1]+up)/i;
            if(b[i]+nup<0||b[i+1]+up<0){
                flag=0;
                break;
            }else if(minx[i]+nup>=0){
                cnt+=max(-(minx[i]+up),0ll);
                flag=1;
                break;
            }
            cnt+=nup-up;
            up=nup;
        }
        if(flag)cout<<cnt<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}