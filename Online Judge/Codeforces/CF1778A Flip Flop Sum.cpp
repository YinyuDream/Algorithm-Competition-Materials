#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,sum,ans;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		sum=0;
		ans=-0x7f7f7f7f;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		for(int i=1;i<n;i++){
			ans=max(ans,sum-2*a[i]-2*a[i+1]);
		}
		cout<<ans<<endl;
	}
}