#include<bits/stdc++.h>
using namespace std;
int T;
long long n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cout<<(int)sqrt(n-1)<<endl;
	}
	return 0;
}