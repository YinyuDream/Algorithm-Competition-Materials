#pragma GCC optimize(2)
#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,a[maxn];
int top,stack[maxn];
int erfen(int left,int right,int k)
{
	while(right>left){
		int mid=(left+right)/2;
		if(stack[mid]<=k)left=mid+1;
		else right=mid;	
	}
	return left;	
} 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(top==0||stack[top]<=a[i])stack[++top]=a[i];
		else stack[erfen(1,top,a[i])]=a[i];
	}
	printf("%d",top);
	return 0;
}
