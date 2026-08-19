#include<cstdio>
#include<cstring>
using namespace std;
long long m;
char a[10000];
int len1,len;
int s1[10000];
int s[10000];
int main()
{	
printf("输入第1个整数\n");
scanf(" %s",a);
	printf("输入第2个整数\n");
		scanf("%lld",&m);
	
	if(m==0)
	{
		printf("Null\n");return 0;
	}
	len1=strlen(a);
	for(int i=1;i<=len1;i++)s1[i]=a[i-1]-'0';
	long long y=0;
	for(int i=1;i<=len1;i++)
	{
		s[i]=(s1[i]+y*10)/m;
		y=(y*10+s1[i])%m;	
	}
	len=1;
	while(s[len]==0&&len<len1)len++;
	for(int i=len;i<=len1;i++)printf("%d",s[i]);
	printf("\n");	 
	return 0;
}
