#include<cstdio>
#include<algorithm>
using namespace std;

int k,t;
struct node{
	int x,y;
}a[1010];

bool cmp(node m,node n)
{
	if(m.y!=n.y)return m.y<n.y;
	else return m.x>n.x;
}
int main(){
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=k;i++)
	{
		 t=a[i].y;
		
	}
	return 0;
}
