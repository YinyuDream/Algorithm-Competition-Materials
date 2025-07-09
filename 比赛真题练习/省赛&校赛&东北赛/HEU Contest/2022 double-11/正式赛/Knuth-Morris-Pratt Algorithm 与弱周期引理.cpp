#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
char s[maxn];
int n,ans,book[26];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		book[s[i]-'a']++;
	for(int i=0;i<=25;i++)
		ans=max(ans,book[i]);
	printf("%d",ans);
	return 0;
}