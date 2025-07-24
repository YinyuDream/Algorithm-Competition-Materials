#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,num;
char s[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s+1;
		num=s[1]-'0';
		for(int i=1;i<n;i++){
			if(s[i+1]=='0'){
				cout<<"+";
			}else{
				if(num==1){
					cout<<"-";
				}else{
					cout<<"+";
				}
				num^=1;
			}
		}
		cout<<endl;
	}
	return 0;
}