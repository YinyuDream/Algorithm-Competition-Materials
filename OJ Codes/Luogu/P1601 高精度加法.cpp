#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10000;
int l1,l2,l;
char a[maxn],b[maxn];
int s1[maxn],s2[maxn],s[maxn];
using namespace std;
int main()
{
	scanf("%s %s",a,b);
	l1=strlen(a);l2=strlen(b);l=l1>l2?l1:l2;
	for(int i=1;i<=l1;i++)s1[i]=a[l1-i]-'0';
	for(int i=1;i<=l2;i++)s2[i]=b[l2-i]-'0';
	for(int i=1;i<=l;i++)
	{
		s[i]+=s1[i]+s2[i];
		s[i+1]+=s[i]/10;
		s[i]%=10;
	}
	if(s[l+1]!=0)l++;
	while(s[l]==0&&l>1)l--;
	for(int i=l;i>=1;i--)printf("%d",s[i]);
	return 0;
}
