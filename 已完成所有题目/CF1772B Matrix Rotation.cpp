#include<bits/stdc++.h>
using namespace std;
int T;
int a[2][2];
bool check()
{
	return a[0][0]<a[0][1]&&a[0][0]<a[1][0]&&a[1][0]<a[1][1]&&a[0][1]<a[1][1];
}
void rotate()
{
	swap(a[0][0],a[0][1]);
	swap(a[1][0],a[1][1]);
	swap(a[0][0],a[1][1]);
}
int main(){
	cin>>T;
	while(T--){
		cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1];
		if(check()){
			cout<<"YES"<<endl;
			continue;
		}
		rotate();
		if(check()){
			cout<<"YES"<<endl;
			continue;
		}
		rotate();
		if(check()){
			cout<<"YES"<<endl;
			continue;
		}
		rotate();
		if(check()){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}