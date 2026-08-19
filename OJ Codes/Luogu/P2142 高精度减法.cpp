#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=10500;
char s1[maxn],s2[maxn];
int a[maxn],b[maxn],sum[maxn];
int lena,lenb,len;

int main()
{
	scanf("%s %s",s1,s2);
	lena=strlen(s1);
	lenb=strlen(s2);
	len=lena>lenb?lena:lenb;
	
	for(int i=1;i<=lena;i++)a[i]=s1[lena-i]-'0'; 
	for(int i=1;i<=lenb;i++)b[i]=s2[lenb-i]-'0';
	int flag=0;
	for(int i=len;i>=1;i--)
	{
		if(a[i]>b[i])
		{
			flag=0;
			break;
		}
		if(a[i]<b[i])
		{
			flag=1;
			printf("-");
			break;
		}
		if(i==1)break; 
	}
	if(flag==1)
	{
		int temp;
		{
			for(int i=1;i<=len;i++)
			{
				temp=a[i];a[i]=b[i];b[i]=temp;
			}
		}
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
	while(sum[len]==0 && len>1)len--;  
	
	for(int i=len;i>=1;i--)printf("%d",sum[i]);
	return 0;
}