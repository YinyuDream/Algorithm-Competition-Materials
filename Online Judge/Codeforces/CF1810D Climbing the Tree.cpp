#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        ll l=0,r=1e18;
        for(int i=1;i<=n;i++){
            int op,a,b,x;
            cin>>op;
            if(op==1){
                cin>>a>>b>>x;
                ll mn,mx;
                if(x==1){
                    mn=1;
                    mx=a;
                }else{
                    mn=(1ll*x-2)*(a-b)+a+1;
                    mx=(1ll*x-1)*(a-b)+a;
                }
                if(mn>r||mx<l){
                    cout<<0<<" ";
                    continue;
                }
                cout<<1<<" ";
                l=max(l,mn);
                r=min(r,mx);
            }else{
                cin>>a>>b;
                ll d,u;
                if(l<=a){
                    d=1;
                }else{
                    d=(l-a)/(a-b)+1;
                    if((l-a)%(a-b)!=0)
                        d++;
                }
                if(r<=a){
                    u=1;
                }else{
                    u=(r-a)/(a-b)+1;
                    if((r-a)%(a-b)!=0)
                        u++;
                }
                if(u==d)cout<<u<<" ";
                else cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}