#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=10000+100;
char a[maxn],b[maxn];
int a1[maxn],b1[maxn],sum[maxn];
int len1,len2,len;
void add()
{
	len=len1>len2?len1:len2;
	for(int i=1;i<=len1;i++)	a1[i]=a[len1-i]-'0';	
	for(int i=1;i<=len2;i++)	b1[i]=b[len2-i]-'0';	
	for(int i=1;i<=len;i++)
	{
		sum[i]+=a1[i]+b1[i];
		sum[i+1]+=sum[i]/10;
		sum[i]%=10;
	}
	if(sum[len+1]>0)len++;
	for(int i=len;i>0;i--)printf("%d",sum[i]);	
}
void jian()
{
	len=len1>len2?len1:len2;
	for(int i=1;i<=len1;i++)	a1[i]=a[len1-i]-'0';	
	for(int i=1;i<=len2;i++)	b1[i]=b[len2-i]-'0';	
	bool flag=0;
	for(int i=len;i>0;i--)
	{
		if(a1[i]>b1[i])
		{
			flag=0;break;
		}
		if(a1[i]<b1[i])
		{
			flag=1;break;
		}
		if(i==1)
		{
			printf("0");
			return ;
		}
	}
	int temp;
	if(flag)
	{
		for(int i=1;i<=len;i++)
		{
			temp=a1[i];a1[i]=b1[i];b1[i]=temp;
		}
		printf("-");
	}
	for(int i=1;i<=len;i++)
	{
		if(a1[i]<b1[i])
		{
			a1[i+1]--;
			a1[i]+=10;
		}
		sum[i]=a1[i]-b1[i];
	}
	while(sum[len]==0)len--;
	for(int i=len;i>0;i--)
	{
		printf("%d",sum[i]);
	}
}
int main()
{
	scanf("%s %s",a,b);
	//printf("%s,,%s",a,b);
	//while(1);
	len1=strlen(a);
	len2=strlen(b);
	//add();
	jian();
	return 0;
}
