#include<cstdio>
#include<queue>
using namespace std;
const int maxn=2000010;
int n,m;
bool bo=0;
int a[maxn],maxx[maxn],change[maxn];
struct node{
	int id,h,maxx;
}p;
queue<node>q;
int main(){
	freopen("goddess.in","r",stdin);
	freopen("goddess.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			printf("%d %d\n",1,a[i]);
		return 0;
	}
	p.h=a[1],p.id=1,p.maxx=a[1];
	q.push(p);
	for(int i=2;i<=n+1;i++)
	{
		p.h=a[i],p.id=i;
		if(i-q.front().id+1>=m||q.back().id-q.front().id+1>=m||i==n+1)
		{
			if((q.back().h<a[i]&&i<=n&&q.back().id<i))q.push(p);
			change[q.front().id]=q.size(),maxx[q.front().id]=q.back().h,q.pop();
		}
		if((q.back().h<a[i]&&i<=n&&q.back().id<i)||q.empty())q.push(p);
	}
	for(int i=1;i<=n-m+1;i++)
		printf("%d %d\n",change[i],maxx[i]);
	return 0;
}
