#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int T,n,flag,color;
int book[26],col[26];
char s[maxn];
int main(){
	cin>>T;
	while(T--){
		flag=color=0;
		memset(book,0,sizeof book);
		memset(col,0,sizeof col);
		cin>>n>>s+1;
		for(int i=1;i<=n;i++){
			color^=1;
			if(book[s[i]-'a']&&col[s[i]-'a']!=color){
				puts("NO");
				flag=1;
				break;
			}
			book[s[i]-'a']=true;
			col[s[i]-'a']=color;
		}
		if(!flag){
			puts("YES");
		}
	}
	return 0;
}