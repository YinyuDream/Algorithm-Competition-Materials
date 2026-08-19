#include<cstdio>
#include<cstring>
using namespace std;
int top=0,len;
char a[300];
int main()
{
	scanf("%s",a);
	len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]=='(')top++;
		else if(a[i]==')')
		{
			if(top==0)
			{
				printf("NO");return 0;
			}
			else top--;
		}
		else;
	}
	if(top==0)printf("YES");
	else printf("NO");
	return 0;
}