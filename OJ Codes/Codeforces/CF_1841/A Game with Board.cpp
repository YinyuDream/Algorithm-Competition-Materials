#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1||n>=5)cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
	return 0;
}