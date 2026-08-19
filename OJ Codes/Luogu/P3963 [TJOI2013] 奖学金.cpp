#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,c,f,ans;
int suma[maxn],sumb[maxn];
struct node{
	int a,b;
}z[maxn];
bool cmp(node a,node b)
{
	return a.a<b.a;
}
priority_queue<int>q;
int main(){
	scanf("%d%d%d",&n,&c,&f);
	for(int i=1;i<=c;i++)
		scanf("%d%d",&z[i].a,&z[i].b);
	sort(z+1,z+c+1,cmp);
	for(int i=1;i<=n/2;i++)
		q.push(z[i].b),suma[i]=suma[i-1]+z[i].b;
	for(int i=n/2+1;i<=c;i++)
	{
		if(z[i].b<q.top())suma[i]=suma[i-1]-q.top()+z[i].b,q.pop(),q.push(z[i].b);
		else suma[i]=suma[i-1];
	}
	while(q.size())q.pop();
	for(int i=c;i>=c-n/2+1;i--)
		q.push(z[i].b),sumb[i]=sumb[i+1]+z[i].b;
	for(int i=c-n/2;i>=1;i--)
	{
		if(z[i].b<q.top())sumb[i]=sumb[i+1]-q.top()+z[i].b,q.pop(),q.push(z[i].b);
		else sumb[i]=sumb[i+1];
	}
	for(int i=n/2+1;i<=c-n/2;i++)
	{
		if(suma[i-1]+sumb[i+1]+z[i].b<=f)
		ans=z[i].a;
	}
	printf("%d",ans!=0?ans:-1);
	return 0;
}
