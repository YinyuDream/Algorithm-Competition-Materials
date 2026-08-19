#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1e5+10;
//二分前提，。一定数据有序。递增或者递减。
 
int n,a[maxn];
int top,stack[maxn];
int erfen(int left,int right,int num)
{
	int mid;
	while(left<right)
	{
		mid=(left+right)/2;
		if(num>=stack[mid])
		{
			left=mid+1;
		}
		else
		{
			right=mid;
		}
	}
	return left;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int k;
	for(int i=1;i<=n;i++)
	{
		if(top==0  || stack[top]<=a[i])
		{
			stack[++top]=a[i];
		}
		else
		{
			k=erfen(1,top,a[i]);
			stack[k]=a[i];
		}
	}
	printf("%d",top);
}
