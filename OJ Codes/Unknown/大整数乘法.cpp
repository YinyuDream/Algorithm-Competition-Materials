#include<cstdio>
#include<cstring>
using namespace std;

const int maxn 10000;
char a[maxn],b[maxn];
int s1[maxn],s2[maxn],s[maxn+maxn];
int len1,len2,len;
int main()
{
	scanf("%s %s",a,b);
	len1=strlen(a);len2=strlen(b);len=len1>len2?len1:len2;
	
	for(int i=1;i<=len1;i++)s1[i]=a[len1-i];
	for(int i=1;i<=len2;i++)s2[i]=b[len2-i];
	
	for(int i=1;i<=n;i++)
	{
		for(int i)	
	}
	return 0;
}
