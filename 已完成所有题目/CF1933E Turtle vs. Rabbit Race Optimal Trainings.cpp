#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n,q;
ll a[maxn],sum[maxn];
ll f(int l,int r,ll u)
{
    ll num=sum[r]-sum[l-1];
    return num*u-num*(num-1)/2;
}
int work(int l,ll u)
{
    if(l==n){
        return n;
    }
    ll sum_l=a[l],sum_r=sum[n]-sum[l-1];
    if(u<=sum_l){
        return l;
    }else if(u>=sum_r){
        return n;
    }else{
        int left=l,right=n;
        while(left<=right){
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            if (f(l,mid1,u)<f(l,mid2,u)) {
                left = mid1 + 1;
            } else {
                right = mid2 - 1;
            }
        }
        if(f(l,left-1,u)==f(l,left,u))return left-1;
        else return left;
    }

}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        cin>>q;
        for(int i=1,l;i<=q;i++){
            ll u;
            cin>>l>>u;
            cout<<work(l,u)<<" ";
        }
        cout<<endl;
	}
	return 0;
}