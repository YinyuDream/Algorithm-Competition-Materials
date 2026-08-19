#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		if(a+b==c)cout<<"+"<<endl;
		else cout<<"-"<<endl;
	}
}