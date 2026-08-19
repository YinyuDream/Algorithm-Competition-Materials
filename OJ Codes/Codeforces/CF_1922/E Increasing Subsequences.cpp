#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
ll pw2[61],ans[201];
ll n;
int main(){
    pw2[0]=1;
    for(int i=1;i<=60;i++)
        pw2[i]=pw2[i-1]*2;
    cin>>T;
    while(T--){
        cin>>n;
        n--;
        int pos=0,tot=0;
        for(int i=60;i>0;i--){
            if(n>=pw2[i]-1){
                n-=pw2[i]-1;
                for(int j=0;j>=1-i;j--)
                    ans[++tot]=j;
                pos=i;
                break;
            }
        }
        for(int i=pos-1;i>0;i--){
            if(n>=pw2[i]){
                n-=pw2[i];
                ans[++tot]=-i;
            }
        }
        for(int i=1;i<=n;i++)
            ans[++tot]=0;
        cout<<tot<<endl;
        for(int i=tot;i;i--)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}