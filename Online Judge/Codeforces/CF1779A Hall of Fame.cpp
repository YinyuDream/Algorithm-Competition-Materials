#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,mx,mn;
char s[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s+1;
		mx=0,mn=n+1;
		for(int i=1;i<=n;i++){
			if(s[i]=='R'){
				mn=i;
				break;
			}
		}
		for(int i=n;i;i--){
			if(s[i]=='L'){
				mx=i;
				break;
			}
		}
		if(mx==0||mn==n+1){
			puts("-1");
		}else if(mn<mx){
			puts("0");
		}else{
			cout<<mx<<endl;
		}
	}
}