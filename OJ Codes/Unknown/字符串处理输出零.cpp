#include<cstdio>
#include<cstring>
using namespace std;
char s[1200];
char f[1200];
int n[1200],topf,topn=1;
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			n[++topn]=s[i]-'0';
		}
		if(s[i]=='+')
		{
			int temp=s[++i]-'0';
			n[topn]=n[topn]+temp;
		}
		else
		{
			int temp=s[++i]-'0';
			n[topn]=n[topn]-temp;
		}
	}
	printf("%d",n[1]);
	return 0;
}
