#include<cstdio>
#include<algorithm>
using namespace std;
int a[5],n=3;
int main(){
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
}
