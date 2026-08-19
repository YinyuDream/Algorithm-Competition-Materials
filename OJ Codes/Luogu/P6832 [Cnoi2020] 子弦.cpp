#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e7+10;
int n,ans,a[200];
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	a[s[i]]++;
	for(int i=1;i<=199;i++)
		ans=max(ans,a[i]);
	printf("%d",ans);
	return 0;
}