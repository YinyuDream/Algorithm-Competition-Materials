#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a[2000005],q[2000005],n,t;
int main()
{
	freopen("data.in","r",stdin);
	freopen("std.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=a[i]%2;
	for(int i=1;i<=n;i++)
	{
		q[++t]=a[i];//入栈
		if(t>1&&q[t]==q[t-1])t-=2;//若相同，删除
	}
	puts(t<2?"YES":"NO");//注意正好一个数也算是
	return 0;
}