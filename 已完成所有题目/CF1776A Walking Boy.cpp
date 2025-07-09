#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,cnt;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[n+1]=1440;
		for(int i=0;i<=n;i++){
			cnt+=(a[i+1]-a[i])/120;
		}
		if(cnt>=2)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}