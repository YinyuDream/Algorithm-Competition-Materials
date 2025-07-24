#include<bits/stdc++.h>
using namespace std;
int T;
double a,b,c;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
        if(a<b)swap(a,b);
        double m=(a+b)/2;
        cout<<(int)ceil((a-m)/c)<<endl;
	}
	return 0;
}