#include<cstdio>
const int maxn=1000;
int a[maxn+10];
int n,k;
int maxk=0,pos=0; 
int cnt=0;
void sort()//排序，可以改成快速排序sort 
{
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t; 
			} 
		}
	}
}
int main()
{
	freopen("maxk.in","r",stdin);
	freopen("maxk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort();
	maxk++;
	for(int i=1;i<=n;i++)
	{
		if(maxk==k)
		{
			pos=i;break;//找到第k大的数，就终止循环。 
		} 
		else if(a[i]>a[i+1])//如果后面的数小，maxk加1 
		{
			maxk++;
		}
	}
	printf("%d\n",a[pos]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[pos]) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
