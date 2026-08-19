#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000;
char a[maxn],b[maxn];
int a1[maxn],b1[maxn],sum[maxn];
int len1,len2,len;

int main()
{
	scanf("%s %s",a,b);
	len1=strlen(a);
	len2=strlen(b);
	for(int i=1;i<=len1;i++)a1[i]=a[len1-i]-'0';//倒序存储，第一位存个位，后面的数据存高位。 
	for(int i=1;i<=len2;i++)b1[i]=b[len2-i]-'0';
	
	for(int i=1;i<=len1;i++)//遍历a1的每一位。 
	{
		for(int j=1;j<=len2;j++)//遍历b1的每一位。用a1的一位乘b1的每一位。 
		{
			sum[i+j-1]+=a1[i]*b1[j];//累加到答案上 
			sum[i+j]+=sum[i+j-1]/10;//处理进位，最多只能进一位。 
			sum[i+j-1]%=10;
		}
	}
	
	len=len1+len2;
	while(sum[len]==0 && len>1)len--;//处理多余的前导0；至少保留一位。 
	for(int i=len;i>=1;i--)printf("%d",sum[i]);
	return 0;
} 
