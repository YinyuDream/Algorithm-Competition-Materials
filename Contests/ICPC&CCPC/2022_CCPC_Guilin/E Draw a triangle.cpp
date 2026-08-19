#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T;
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-y*(a/b);
}
int main(){
    cin>>T;
    while(T--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2){
            cout<<x1+1<<" "<<0<<endl;
        }else if(y1==y2){
            cout<<0<<" "<<y1+1<<endl;
        }else{
            y2-=y1;
            x2-=x1;
            bool mir_x=false,mir_y=false;
            if(y2<0){
                y2=-y2;
                mir_y=true;
            }
            if(x2<0){
                x2=-x2;
                mir_x=true;
            }
            ll x3=0,y3=0;
            exgcd(x2,y2,y3,x3);
            if(!mir_x) x3=-x3;
            if(mir_y) y3=-y3;
            cout<<x1+x3<<" "<<y1+y3<<endl;
        }
    }
    return 0;
}