#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+20;
int n,m;
int a[maxn];
int left,right;
int stack[maxn];
int check(int k)//k是假设的最小距离 
{
	int top=0;
	for(int i=1;i<=n;i++)//每一个瓶盖依次遍历。 
	{
		if(top==0 || a[i]-stack[top]>=k)//满足条件的瓶盖就入栈。 
		{
			stack[++top]=a[i];		
		}
	}
	return top;//返回瓶盖个数 
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	left=1;right=a[n];
	while(left<=right)//当相等时，再判断一次， 
	{
		int mid=(left+right)/2;
		int book=check(mid);//book是当最短距离为mid时，能得到的瓶盖个数。 
		if(book<m)right=mid-1;//假如个数比m小，说明mid太大，在满足mid距离下找不够 m个瓶盖 
		else left=mid+1;
		//假如个数>=m,那答案有可能是mid（1），也有可能 在mid右边，（2）
		//（1）如果mid==9是答案，则left=9+1;9后面的数都不满足，最后要么right=left，要么=left-1; 
		//     如果等于left ,循环再执行1次 ，right=9.就是答案。 
		// 举例：1 10 19 22 找出3个瓶盖。假如此时left=7,right=12,自己慢慢推。 
	}
	printf("%d",right);
	return 0;
}