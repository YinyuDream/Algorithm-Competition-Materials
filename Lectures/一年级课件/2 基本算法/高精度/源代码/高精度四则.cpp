#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=10000;
char s1[maxn],s2[maxn];
int a[maxn],b[maxn],sum[maxn];
int lena,lenb,len;

void addd()
{
	for(int i=1;i<=lena;i++)a[i]=s1[lena-i]-'0';//转换成整数，并反向存储。 
	for(int i=1;i<=lenb;i++)b[i]=s2[lenb-i]-'0';
	

	for(int i=1;i<=len;i++)//运算， 
	{
		sum[i]+=a[i]+b[i];
		sum[i+1]+=sum[i]/10;//处理进位 
		sum[i]%=10;	
	}
	if(sum[len+1]>0)len++;
	while(sum[len]==0 && len>1)len--; //去除前导0； 
	for(int i=len;i>=1;i--)printf("%d",sum[i]);
}
void jian()
{
	for(int i=1;i<=lena;i++)a[i]=s1[lena-i]-'0';
	for(int i=1;i<=lenb;i++)b[i]=s2[lenb-i]-'0';
	
	bool flag=0;//默认a>b。 
	for(int i=len;i>0;i--)
	{
		if(a[i]>b[i])
		{
			flag=0;
			break;
		}
		if(a[i]<b[i])
		{
			flag=1;
			break;
		}
		if(i==1)
		{
			printf("0");
			return ;
		}
	}
	if(flag==1)
	{
		int temp=0;
		for(int i=1;i<=len;i++)
		{
			temp=a[i];a[i]=b[i];b[i]=temp;
		}
		printf("-");
	}
	
	for(int i=1;i<=len;i++)
	{
		sum[i]=a[i]-b[i];
		if(sum[i]<0)
		{
			sum[i]+=10;
			a[i+1]--;
		}
	}
	
	while(sum[len]==0) len--;
	
	for(int i=len;i>=1;i--)printf("%d",sum[i]);
}

void cheng()
{
	for(int i=1;i<=lena;i++)a[i]=s1[lena-i]-'0';
	for(int i=1;i<=lenb;i++)b[i]=s2[lenb-i]-'0';//从个位开始乘，所以反向存储。 
	len=lena+lenb;
	
	for(int i=1;i<=lena;i++)
	{
		for(int j=1;j<=lenb;j++)
		{
			sum[i+j-1]+=a[i]*b[j];
			sum[i+j]+=sum[i+j-1]/10;//处理进位。 
			sum[i+j-1]%=10;
		}
	}
	
	while(sum[len]==0 && len>1)len--;
	for(int i=len;i>=1;i--)printf("%d",sum[i]);
}

void chu()
{
	int k;
	scanf("%s %d",s1,&k);
	len=strlen(s1);
	for(int i=1;i<=len;i++)a[i]=s1[i-1]-'0';  
	//从高位开始运算，所以高位在前，不用反向存储。 
	int y=0;//余数初始化0 
	for(int i=1;i<=len;i++)
	{
		sum[i]=(a[i]+y*10)/k;//模拟小学除法。 
		y=(a[i]+y*10)%k;
	}
	
	int t=1;//去除前导0 
	while(sum[t]==0)
	{
		t++;
		if(t>len)//如果答案都是0,t就移动到len的后面。 
		{
			printf("0");
			return ;	
		}
	}
	
	for(int i=t;i<=len;i++)printf("%d",sum[i]);
}
int main()
{
	scanf("%s %s",s1,s2);
	//printf("%s,,%s",s1,s2);
	
	lena=strlen(s1);
	lenb=strlen(s2);
	len=lena>lenb?lena:lenb;
	//addd();
	
	jian();
	//chu();
	return 0;
}
