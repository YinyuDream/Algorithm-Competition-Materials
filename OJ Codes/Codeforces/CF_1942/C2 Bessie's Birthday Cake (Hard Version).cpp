#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,x,y;
int a[maxn],b[maxn];
bool cmp(int _x,int _y){
    int _a=_x%2,_b=_y%2;
    if(_a==0&&_b==1)return true;
    else if(_a==1&&_b==0)return false;
    else return _x<_y;
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>x>>y;
        for(int i=1;i<=x;i++) cin>>a[i];
        sort(a+1,a+x+1);
        int num=a[1];
        for(int i=1;i<=x;i++)
            a[i]-=num-1;
        int ans=x-2;
        for(int i=1;i<x;i++)
            if(a[i+1]-a[i]==2) ans++;
        if(a[x]==n-1&&a[1]==1) ans++;
        int cnt=0;
        for(int i=1;i<x;i++){
            int d=a[i+1]-a[i];
            if(d>=3)
                b[++cnt]=d;
        }
        int d=n-a[x]+1;
        if(d>=3){
            b[++cnt]=d;
        }
        sort(b+1,b+cnt+1,cmp);
        for(int i=1;i<=cnt;i++){
            int num=(b[i]-1)/2;
            if(y>=num){
                y-=num;
                ans+=num+b[i]/2;
            }else{
                ans+=2*y;
                y=0;
            }
            if(y==0)break;
        }
        cout<<ans<<endl;
    }
    return 0;
}