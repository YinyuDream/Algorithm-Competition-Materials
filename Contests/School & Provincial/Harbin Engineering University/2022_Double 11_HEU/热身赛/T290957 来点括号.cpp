#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn],val[maxn],remain[maxn];
signed main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		val[2]=a[1]/a[2],remain[2]=a[1]%a[2];
		for(int i=3;i<=n;i++)
			val[i]=val[i-1]*a[i]+remain[i-1]*a[i]/a[2],
			remain[i]=remain[i-1]*a[i]%a[2];
		if(!remain[n])puts("Yes");
		else puts("No");
	}
}