#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n;
char s[maxn],tp;
int main(){
	cin>>T;
	while(T--){
		tp=0;
		cin>>n>>s+1;
		for(int i=1;i<=n;i++){
			if(!tp){
				tp=s[i];
				cout<<s[i];
			}else if(tp==s[i]){
				tp=0;
			}
		}
		cout<<endl;
	}
	return 0;
}