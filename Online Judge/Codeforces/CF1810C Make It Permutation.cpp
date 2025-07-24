#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
long long c,d,ans;
int a[maxn],cnt[maxn];
int main(){
	cin>>T;
	while(T--){
		ans=0x7f7f7f7f7f7f7f7fll;
		cin>>n>>c>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cnt[i]=0;
		}
		sort(a+1,a+n+1);
		for(int i=0;i<n;i++){
			if(a[i]!=a[i+1]){
				cnt[i+1]++;
			}
		}
		for(int i=1;i<=n;i++){
			cnt[i]+=cnt[i-1];
		}
		for(int i=1;i<=n;i++){
			ans=min(ans,c*(n-cnt[i])+d*(a[i]-cnt[i]));
		}
		ans=min(ans,c*n+d);
		cout<<ans<<endl;
	}
	return 0;
}