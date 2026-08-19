#include<bits/stdc++.h>
using namespace std;
int len=1,cnt;
const int maxn=1e6+10;
char s[maxn];
int main(){
	scanf("%s",s+1);
	while(s[len])len++;
	len--;
	while(s[len]=='1')len--;
	for(int i=len;i>=1;i--)
		if(s[i]!=s[i-1])
			cnt++;
	printf("%d",cnt);
	return 0;
}