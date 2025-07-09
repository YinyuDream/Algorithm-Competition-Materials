#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
void solve(){
    int n,x=0,y=0,cnt_p=0,cnt_n=0;
    cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++){
        int p=a[i],q=b[i];
        if(p>q){
            x+=p;
        }else if(p<q){
            y+=q;
        }else{
            if(p==1){
                cnt_p++;
            }else if(p==-1){
                cnt_n++;
            }
        }
    }
    auto check=[&](int mid){
        int pos=cnt_p,neg=cnt_n,_x=x,_y=y;
        int val=max(0,mid-_x)+max(0,mid-_y);
        if(val>pos)return false;
        pos-=val;
        _x=max(_x,mid);
        _y=max(_y,mid);
        pos+=_x-mid+_y-mid;
        return pos>=neg;
    };
    int l=-1e6,r=1e6;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<r<<endl;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}