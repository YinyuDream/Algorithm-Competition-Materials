#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
	cin>>n>>a>>b>>c;
	if(n>5)cout<<"art";
	else if(n>3){
		if(b>c)cout<<"art";
		else cout<<"comprehensive";
	}else{
		int mn=min(a,min(b,c));
		if(mn==a)cout<<"library";
		else if(mn==b)cout<<"comprehensive";
		else cout<<"art";
	}
	return 0;
}