#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n==3){
			cout<<"NO";
		}else if(n%2==0){
			puts("YES");
			for(int i=1,sign=1;i<=n;i++){
				cout<<sign<<" ";
				sign*=-1;
			}
		}else{
			puts("YES");
			for(int i=1,sign=1;i<=n;i++){
				cout<<sign*(n/2-i%2)<<" ";
				sign*=-1;
			}
		}
		puts("");
	}
	return 0;
}