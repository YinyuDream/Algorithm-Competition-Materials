#include<cstdio>
using namespace std;
int n;
int a[2][5010];
void f(int &x,int &y)
{
     int temp=x;
     x=y;
     y=temp;    
}
int main()
{
    scanf("%d",&n); 
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[0][i],&a[1][i]);
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
             
            if(a[1][j]<=a[1][j+1])
            {
            f(a[1][j],a[1][j+1]);
            f(a[0][j],a[0][j+1]);   
            }
             
        }
    }
    for(int i=1,c,s;i<=n;i++)
    {
         s=1;
       	if(a[1][i]==a[1][i+1])c=i; 
        while(a[1][i]==a[1][i+1])
        {
            i++;
            s++;
        }
        if(s>1)
        {
        	for(int l=c;l<=i-1;l++)
        	{
        		for(int j=i-1;j>=l;j--)
        		{
        			if(a[0][j]>a[0][j+1])f(a[0][j],a[0][j+1]);
				}
			}
		}
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",a[0][i],a[1][i]);
    }
    return 0;
}
