#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,cnt;
char s[maxn];
int main(){
	scanf("%d\n%s",&n,s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='a')
			cnt++;
	for(int i=n;i>=cnt;i--)
		if(cnt>i/2){
			printf("%d",i);
			break;
		}
	return 0;
}