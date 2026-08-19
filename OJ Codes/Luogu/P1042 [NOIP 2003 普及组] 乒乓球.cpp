#include<cstdio>
#include<cmath>
using namespace std;
char ch;
int a,b,c,d,i,j;
int x[100000][2],y[100000][2];
int main()
{
	while(1)
	{
		scanf(" %c",&ch);
		if(ch=='W')
		{
			a++;c++;
		}
		if(ch=='L')
		{
			b++;d++;
		}	
		if((a>=11||b>=11)&&abs(a-b)>=2)
		{
			i++;
			x[i][0]=a;x[i][1]=b;
			a=b=0;
		}
		if((c>=21||d>=21)&&abs(c-d)>=2)
		{
			j++;
			y[j][0]=c;y[j][1]=d;
			c=d=0;
		}
		if(ch=='E')
		{
			i++;
			x[i][0]=a;x[i][1]=b;	
			j++;
			y[j][0]=c;y[j][1]=d;
			break;		
		}
	}
	for(int q=1;q<=i;q++)printf("%d:%d\n",x[q][0],x[q][1]);
	printf("\n");
	for(int k=1;k<=j;k++)printf("%d:%d\n",y[k][0],y[k][1]);
	return 0;
}
