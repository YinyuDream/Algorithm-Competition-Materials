#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,q;
int a[maxn],cnt[maxn];
long long sum[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            cnt[i]=cnt[i-1];
            if(a[i]==1){
                cnt[i]++;
            }
        }
        for(int i=1,l,r;i<=q;i++){
            cin>>l>>r;
            if(l==r){
                cout<<"NO"<<endl;
                continue;
            }
            if(sum[r]-sum[l-1]-(r-l+1)>=cnt[r]-cnt[l-1]){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
	}
	return 0;
}