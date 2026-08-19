#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,a[maxn];
void work()
{
	int a0=a[1]/2,b0=a[1]-a0;
	if(max(a0,b0)>a[3])puts("nice");
	else {
		int b1=a[2]-a0;
		if(max(a0,b0)<a[3]){
			int a1=a[3]-b1;
			if(a1+b0>a[2])puts("nice");
			else printf("simple\n2\n%d %d\n%d %d",a1,a0,b1,b0);
		}else if(max(a0,b0)==a[3]){
			printf("simple\n2\n%d %d\n%d %d",-1,a0,b1,b0);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1)printf("simple\n1\n%d %d",a[2],a[1]);
	else work();
	return 0;
}
