#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n;
ll power(ll x,ll y)
{
	ll ans=1;
	for(int i=1;i<=y;i++){
		ans*=x;
	}
	return ans;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n%2==0){
			cout<<1<<" "<<n/2<<endl;
			continue;
		}
		for(ll x=2;x<=30;x++){
			for(ll y=2;y<=30;y++){
				if(power(x,y)*y+power(y,x)*x==n){
					cout<<x<<" "<<y<<endl;
					goto flag;
				}
			}
		}
		cout<<-1<<endl;
		flag:;
	}
	return 0;
}