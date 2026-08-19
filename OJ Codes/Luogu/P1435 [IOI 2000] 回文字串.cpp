#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n;
char a[maxn],b[maxn];
int main(){
	scanf("%s",a+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++)
	b[i]=a[i];
	reverse(b+1,b+n+1);
	return 0;
}
