#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
        if(c%2==0){
            if(a>b)cout<<"First";
            else cout<<"Second";
        }else{
            if(a<b)cout<<"Second";
            else cout<<"First";
        }
        cout<<endl;
	}
	return 0;
}