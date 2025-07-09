#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,x;
long long ans;
int a[maxn];
int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i]+x;
	}
	cout<<ans;
}