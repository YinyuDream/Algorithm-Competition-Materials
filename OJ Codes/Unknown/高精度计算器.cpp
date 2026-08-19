#include<cstdio>
#include<cstring>
#include<conio.h>
using namespace std;
int n,cnt;
long long m;
int b1,b2,bc;
const int maxn=10000;
char a[maxn],b[maxn],c='+';
int s1[maxn],s2[maxn],s[maxn];
int len1,len2,len;
int bijiao()
{
	for(int i=len;i>=1;i--)
	{
		if(s1[i+b1]>s2[i+b2])return 1;
		if(s1[i+b1]<s2[i+b2])return -1;
		if(i==1)return 0;
	}	
}
void jiaohuan()
{
	int temp;
	{
		for(int i=1;i<=len;i++)
		{
			temp=s1[i+b1];s1[i+b1]=s2[i+b2];s2[i+b2]=temp;
		}
	}
}
void add()
{
	len=len1>len2?len1:len2;
	for(int i=1;i<=len;i++)
	{
		s[i]+=s1[i+b1]+s2[i+b2];
		s[i+1]+=s[i]/10;
		s[i]%=10;
	}
	if(s[len+1]!=0)len++;
	while(s[len]==0&&len>1)len--;
	if(cnt==2)printf("-");
	for(int i=len;i>=1;i--)printf("%d",s[i]);
	printf("\n");
	return ;		
}
void redu()
{
	if(b1==1)jiaohuan();
	if(1)
	{
		len=len1>len2?len1:len2;
		int k=bijiao();
		if(k==0)
		{
			printf("0\n");return ;
		}
		if(k==-1)
		{
			jiaohuan();printf("-");
		}
		for(int i=1;i<=len;i++)
		{
			s[i]+=s1[i+b1]-s2[i+b2];
			if(s[i]<0)
			{
				s[i]+=10;
				s[i+1]--;
			}
		}
		while(s[len]==0&&len>1)len--;
		for(int i=len;i>=1;i--)printf("%d",s[i]);
		printf("\n");
		return ;		
	}		
}
void cheng()
{
	len=len1+len2-b1-b2;
	for(int i=1;i<=len;i++)printf("%d %d ",s1[i],s2[i]);
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			s[i+j-1]+=s1[i]*s2[j];
			s[i+j]+=s[i+j-1]/10;
			s[i+j-1]%=10;
		}
	}
	while(s[len]==0&&len>1)len--;
	if(cnt==1)printf("-"); 
	//for(int i=len;i>=1;i--)printf("%d",s[i]);
	printf("\n");
	return ;
}
void chu1()
{
	if(m==0)
	{
		printf("Null\n");return ;
	}
	for(int i=1;i<=len1;i++)s1[i]=a[i-1]-'0';
	long long y=0;
	for(int i=1;i<=len1;i++)
	{
		s[i]=(s1[i]+y*10)/m;
		y=(y*10+s1[i])%m;	
	}
	len=1;
	while(s[len]==0&&len<len1)len++;
	if(cnt==2)
	for(int i=len;i<=len1;i++)printf("%d",s[i]);
	printf("\n");
	return ;		
} 
int main()
{
	printf("高精度计算程序V2.0,按任意键继续......\n");getch();
	printf("输入第1个整数\n");scanf(" %s",a);
	if(a[0]=='-')
	{
		cnt++;b1=1; 
	}
	printf("输入运算符\n");scanf(" %c",&c);
	if(c=='-')
	{
		cnt++;bc=1;  
	}
	printf("输入第2个整数\n");
	if(c=='/')
	{
		scanf("%lld",&m);
		if(m<0)cnt++;
	}
	else
	{
		scanf(" %s",b);
		if(b[0]=='-')
		{
			cnt++;b2=1;
		}	
	}
	len1=strlen(a);len2=strlen(b);
	if(b2==1&&bc==1&&c!='*')
	{
		for(int i=1;i<=len2;i++)b[i-1]=b[i];
		b[len2]='\0';len2--;cnt-=2;bc=0;b2=0;	
	}
	if(b2==1&&bc==0&&c!='*')
	{
		for(int i=1;i<=len2;i++)b[i-1]=b[i];
		b[len2]='\0';len2--;bc=1;b2=0;	
	} 
	len=len1>len2?len1:len2;
	for(int i=1;i<=len1;i++)s1[i]=a[len1-i+b1]-'0';
	for(int i=1;i<=len2;i++)s2[i]=b[len2-i+b2]-'0';
	//printf("%d %d %d %d ",b1,bc,b2,len);
	if(c!='*'&&cnt%2==0)add();
	else if(c!='*'&&cnt==1)redu();
	else if(c=='*')cheng();
	else chu1();
	
	printf("按任意键退出程序\n"); 
	getch(); 
	return 0;
}
