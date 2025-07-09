#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,ans;
int a[maxn],b[maxn];
int main(){
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		for(int i=1;i<=n;i++)
			if(a[i]-b[i]>0)
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}