#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n=1;
char s[maxn];
int main(){
	while(cin>>s){
		n=1;
		while(s[n]){
			if(s[n]=='\\'){
				if(s[n+1]=='r'&&s[n+2]=='\\'&&s[n+3]=='n')
					puts("windows");
				else if(s[n+1]=='r')
					puts("mac");
				else puts("linux");
				return 0;
			}
			n++;	
		}
	}
	return 0;
}