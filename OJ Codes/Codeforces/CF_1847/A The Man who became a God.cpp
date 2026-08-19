#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,k,ans;
int a[maxn],b[maxn];
int main(){
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<n;i++)
			b[i]=abs(a[i]-a[i+1]);
		sort(b+1,b+n);
		for(int i=1;i<=n-k;i++)
			ans+=b[i];
		cout<<ans<<endl;
	}
	return 0;
}