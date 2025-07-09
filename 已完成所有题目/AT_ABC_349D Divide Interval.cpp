#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
ll a,b,pw2[61];
ll l[N],r[N],cnt;
int main(){
    pw2[0]=1;
    for(int i=1;i<=60;i++) pw2[i]=pw2[i-1]*2;
    cin>>a>>b;
    while(a<b){
        for(int i=60;i>=0;i--)
            if(a%pw2[i]==0&&a+pw2[i]<=b){
                l[++cnt]=a;
                r[cnt]=a+pw2[i];
                a+=pw2[i];
                break;
            }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++) cout<<l[i]<<" "<<r[i]<<endl;
}