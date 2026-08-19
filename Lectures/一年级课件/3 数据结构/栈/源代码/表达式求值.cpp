#include<cstdio>
#include<cstring>
using namespace std;

int num[1000];
char ysf[1000];
int topn,topy;
char ch[1000];
int temp;

int main()
{
	scanf("%s",ch);
	int len=strlen(ch);
	for(int i=0;i<=len;i++)
	{
		if(ch[i]>='0' && ch[i]<='9')//数字直接入栈 
		{
			num[++topn]=ch[i]-'0';
		}
		else
		{
			if(ch[i]=='+' || ch[i]=='-')	ysf[++topy]=ch[i];//+-号直接入栈 
			else if(ch[i]=='*')//如果是乘号除号，就直接运算。 
			{
				temp=ch[++i]-'0';
				num[topn]=num[topn]*temp;//栈顶的数字和后面的数字运算。 
			}
			else if(ch[i]=='/')
			{
				temp=ch[++i]-'0';
				num[topn]=num[topn]/temp;
			}
		}
	}
	while(topy>0)//符号栈只剩下加减。 
	{
		temp=num[topn--];//取出栈顶数字，并且出栈。 
		if(ysf[topy]=='+')
		{
			num[topn]=num[topn]+temp;//当前栈顶数字和刚才取出的数字temp运算。 
			topy--;
		}
		if(ysf[topy]=='-')
		{
			num[topn]=num[topn]-temp;
			topy--;
		}
	}
	printf("%d",num[1]);
	return 0;
}
