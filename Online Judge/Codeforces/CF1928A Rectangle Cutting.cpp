#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b;
        if(a<b)
            swap(a,b);
        if(a%2!=0&&b%2!=0){
            cout<<"No"<<endl;
            continue;
        }
        if(a==b*2&&b%2==1){
            cout<<"No"<<endl;
        }else{
            cout<<"Yes"<<endl;
        }
	}
	return 0;
}