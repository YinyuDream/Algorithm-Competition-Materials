#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,nextn[maxn];
char a[maxn];
int main(){
	scanf("%d\n%s",&n,a);
	for(int i=1,j=0;i<n;i++)
	{
		while(j&&a[j]!=a[i])
		j=nextn[j-1];
		j+=(a[j]==a[i]);
		nextn[i]=j;
	}
	printf("%d",n-nextn[n-1]);
	return 0;
}
