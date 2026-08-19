#include<bits/stdc++.h>
using namespace std;
int n,L,R,ans;
int l,r;
int main(){
	cin>>n>>L>>R;
	l=L%n,r=R%n;
	if(l<=r&&R-L+1<=n)ans=r;
	else ans=n-1;
	cout<<ans;
	return 0;
}