#include<bits/stdc++.h>
using namespace std;
long long a[5];
int q;
int main(){
	cin>>q;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=4;j++){
			cin>>a[j];
		} 
		sort(a+1,a+5);
		if((a[1]+a[4])!=(a[2]+a[3])){
			cout<<0<<endl;
		}else if(a[1]==a[2]&&a[2]==a[3]){
			cout<<1<<endl;
		}else if(a[1]==a[2]){
			cout<<4<<endl; 
		}else{
			cout<<8<<endl;
		}
	}
	return 0;
} 
