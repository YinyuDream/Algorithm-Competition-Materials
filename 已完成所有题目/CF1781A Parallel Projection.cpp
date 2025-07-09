#include<bits/stdc++.h>
using namespace std;
int T,w,d,h,a,b,f,g;
int main(){
	cin>>T;
	while(T--){
		cin>>w>>d>>h>>a>>b>>f>>g;
		cout<<min(h+abs(b-g)+min(a+f,2*w-a-f),h+abs(a-f)+min(b+g,2*d-b-g))<<endl;
	}
	return 0;
}