#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int x[maxn],y[maxn];
bool check(int origin,int nx,int ny,int seg_l,int seg_r)
{
    int A_1=nx,B_1=(x[seg_l]-x[seg_r]),C_1=x[seg_r]-x[origin];
    int A_2=ny,B_2=(y[seg_l]-y[seg_r]),C_2=y[seg_r]-y[origin];
    int delta=A_1*B_2-A_2*B_1;
    if(delta==0)return false;
    if(delta*(B_2*C_1-B_1*C_2)<0)return false;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        int dx=x[2]-x[1],dy=y[2]-y[1],cnt=0;
        for(int i=2;i<=n;i++){
            if(check(1,dy,-dx,i,i+1))
                cnt++;
        }
        if(check(1,dy,-dx,n,1))
            cnt++;
    }
    return 0;
}