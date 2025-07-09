#include<bits/stdc++.h>
using namespace std;
int T;
char a[3];
int main(){
	cin>>T;
	while(T--){
		cin>>a;
		cout<<a[0]-'0'+a[2]-'0'<<endl;
	}
	return 0;
}