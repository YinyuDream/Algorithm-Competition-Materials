#include<cstdio>
#include<cstring>
using namespace std;
char s[1200];
char f[1200];
int n[1200],topf,topn;
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
        else if(s[i]=='+'||s[i]=='-')
        {
        	if(f[topf]=='+'||f[topf]=='-')
        	{
        		if(f[topf]=='+')
        		{
        			int temp=n[topn]+n[--topn];
            		n[topn]=temp;
            		f[topf]=s[i];
				}
				else
				{
					int temp=n[topn];
					topn--;
            		n[topn]=n[topn]-temp;
            		f[topf]=s[i];
				}
			}
            else
            {
            	f[++topf]=s[i];	
			}
        }
        else if(s[i]=='*')
        {
        	n[topn]=n[topn]*(s[++i]-'0');	
		}
		else if(s[i]=='/')
        {
        	n[topn]=n[topn]/(s[++i]-'0');	
		}
    }
    if(topf!=0)
    {
    	if(f[topf]=='+')
    	{
    		int temp=n[topn]+n[--topn];
    		n[topn]=temp;
    		topf--;
		}
		else
		{
			int temp=n[topn];
			topn--;
            n[topn]=n[topn]-temp;
			topf--;	
		}
	}
	printf("%d",n[1]);
    return 0;
}