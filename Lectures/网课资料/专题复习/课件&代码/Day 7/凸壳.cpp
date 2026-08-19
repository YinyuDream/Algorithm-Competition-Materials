#include<cstdio>
#include<cstring>
//ºá×ø±êÉýÐòÀ´£¬Î¬»¤ÉÏÍ¹¿Ç

struct Point
{
	double x,y;
};

Point que[100];
int top,tail;

Point minus(Point a,Point b)
{
	Point c;
	c.x=a.x-b.x;
	c.y=a.y-b.y;
	return c;
}

double chaji(Point a,Point b)
{
	return (a.x*b.y-a.y*b.x);
}

void newpoint(Point p)
{
	while(tail-top>=1 && chaji( minus(p,que[tail-1]) , minus(que[tail],que[tail-1]) )<0)
		tail--;
	tail++;
	que[tail]=p;
}

int main()
{
	top=1;tail=0;
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		Point p;
		scanf("%lf%lf",&p.x,&p.y);
		newpoint(p);
	}
}
