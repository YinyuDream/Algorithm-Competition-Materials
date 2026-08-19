#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000;
char a1[maxn];
int a[maxn],b,sum[maxn];
int len1,len;

int main()
{
	scanf("%s %d",a1,&b);
	len1=strlen(a1);
	for(int i=1;i<=len1;i++)a[i]=a1[i-1]-'0';//除法从高位开始运算，不需要倒置 
	int y=0;//余数初始值0 
	for(int i=1;i<=len1;i++)
	{
		sum[i]=(y*10+a[i])/b;//
		y=(y*10+a[i])%b;
	}	
	len=1;
	while(sum[len]==0 && len<len1)len++;//去除前导0 ，至少保留一位。 
	for(int i=len;i<=len1;i++)printf("%d",sum[i]);
	return 0;
} 
