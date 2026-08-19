#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n;
char a[maxn];
int nextn[maxn];
void kmp()
{
	int j=0;
	for(int i=1;i<n;i++){
		while(a[i]!=a[j]&&j)j=nextn[j-1];
		j+=(a[i]==a[j]);
		nextn[i]=j;
	}
}
int main(){
	scanf("%d\n%s",&n,a);
	kmp();
	printf("%d",n-nextn[n-1]);
	return 0;
}