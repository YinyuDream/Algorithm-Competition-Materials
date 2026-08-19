#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
bool a[maxn];
int main(){
	for(long long k=2;k<sqrt(maxn);k++){
		long long pow=k*k*k,num=k*k+k+1;
		while(num<=maxn){
			a[num]=true;
			pow*=k;
			num=(pow-1)/(k-1);
		}
	}
	cin>>T;
	while(T--){
		cin>>n;
		if(a[n]==1)cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
	return 0;
}