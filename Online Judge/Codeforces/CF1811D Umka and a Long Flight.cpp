#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=50;
int T,n;
ll x,y;
ll f[maxn];
int main(){
    cin>>T;
    f[0]=f[1]=1;
    for(int i=2;i<maxn;i++)
        f[i]=f[i-1]+f[i-2];
    while(T--){
        bool flag=true;
        cin>>n>>x>>y;
        int dir=0;//0:横着，1:竖着
        int wid=f[n],len=f[n+1];
        for(int i=n;i;i--){
            if(dir==0){
                if(y>f[i]){
                    len-=f[i];
                    y-=f[i];
                }else if(y<=len-f[i]){
                    len-=f[i];
                }else{
                    flag=false;
                }
                dir=1;
            }else{
                if(x>f[i]){
                    wid-=f[i];
                    x-=f[i];
                }else if(x<=wid-f[i]){
                    wid-=f[i];
                }else{
                    flag=false;
                }
                dir=0;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}