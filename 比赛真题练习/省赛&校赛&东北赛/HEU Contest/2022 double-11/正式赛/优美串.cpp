#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
long long ans;
char s[maxn];
int main(){
	scanf("%d\n%s",&n,s+1);
	ans=n;
	for(int i=2;i<=n;i++)
		if(s[i]!=s[i-1])
			ans+=i-1;
	printf("%lld",ans);
	return 0;
}