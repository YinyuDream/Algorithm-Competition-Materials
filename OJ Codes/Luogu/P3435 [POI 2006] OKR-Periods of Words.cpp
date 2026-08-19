#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,nextn[maxn];
char a[maxn];
long long ans;
int main(){
	scanf("%d\n%s",&n,a);
	for(int i=1,j=0;i<n;i++)
	{
		while(j&&a[i]!=a[j])j=nextn[j-1];
		j+=(a[i]==a[j]);
		nextn[i]=j;
	}
	for(int i=0,j;i<n;i++)
	{
		j=nextn[i];
		while(nextn[j-1])j=nextn[j-1];
		if(j)ans+=i-j+1;
		nextn[i]=j;
	}
	printf("%lld",ans);
	return 0;
}
