#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int num;
			cin>>num;
			cout<<n-num+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}