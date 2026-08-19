#include<cstdio>
#include<algorithm>
using namespace std;
const int K=1e3+10;
int n,m,k;
struct node{
	int x,y,cnt;
}pos[K];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
void lsh()
{
	int *b=new int[k+10];
	for(int i=1;i<=k;i++)
	b[i]=pos[i].y;
	sort(b+1,b+k+1);
	int cnt=unique(b+1,b+k+1)-b-1;
	for(int i=1;i<=k;i++)
	pos[i].y=lower_bound(b+1,b+cnt+1,pos[i].y)-b;
	delete[] b;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c),a++,b++;
		pos[i].x=a,pos[i].y=b,pos[i].cnt=c;
	}
	sort(pos+1,pos+k+1,cmp);
	lsh();
	for(int i=1;i<=n;i++)
	printf("x:%d,y:%d\n",pos[i].x,pos[i].y);
	return 0;
} 
