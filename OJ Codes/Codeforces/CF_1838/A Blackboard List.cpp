#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int T,n;
int a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		if(a[1]<0)cout<<a[1]<<endl;
		else cout<<a[n]<<endl;
	}
}