#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1e6+10;
int a[maxn]; 
int n,m,ans;

int stack[maxn];
bool check(int k)
{
	int top=0;
	for(int i=1;i<=n;i++)
	{
		if(top==0||a[i]-stack[top]>=k)
		{
			stack[++top]=a[i];
		}
	}
	if(top<m)return 0;
	else return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int left=1,right=a[n];
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(check(mid))left=mid+1;
		else right=mid-1;
	}
	printf("%d",right);
	return 0;
}
