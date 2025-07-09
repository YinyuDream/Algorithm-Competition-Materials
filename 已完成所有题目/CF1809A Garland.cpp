#include<bits/stdc++.h>
using namespace std;
int T,mx,a[11];
char s[5];
int main(){
	cin>>T;
	while(T--){
		mx=0;
		memset(a,0,sizeof a);
		cin>>s+1;
		a[s[1]-'0']++,a[s[2]-'0']++,a[s[3]-'0']++,a[s[4]-'0']++;
		for(int i=0;i<=9;i++){
			mx=max(mx,a[i]);
		}
		if(mx==1){
			puts("4");
		}else if(mx==4){
			puts("-1");
		}else if(mx==3){
			puts("6");
		}else{
			puts("4");
		}
	}
	return 0;
}