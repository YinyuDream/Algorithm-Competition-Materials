#include<queue>

using namespace std;

struct point
{
	int p,d;
	point(){p=d=0;}
	point(int a,int b){p=a;d=b;}
};

bool operator<(const point &a,const point &b)
{
	return a.d>b.d;
}

priority_queue<point> heap;

void prim(int s)
{
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	for (int i=1;i<=n;i++)
		heap.push(point(i,dist[i]));
	for (int i=1;i<=n;i++)
	{
		while (right[heap.top().p])
			heap.pop();
		point now = heap.top();
		heap.pop();
		int p=now.p,d=now.d;
		right[p]=true;
		for (int j=first[p];j!=0;j=ed[j].next)
		{
			int e = ed[j].e;
			int d = ed[j].d;
			if (dist[e] > d)
			{
				dist[e]=d;
				heap.push(point(e,d));
			}
		}
	}
}

