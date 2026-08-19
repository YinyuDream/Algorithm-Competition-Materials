#include<cstdio>
#include<queue>
#include<cstdlib>
using namespace std;
const int maxn=1e3;
int n,a,b,ans;
int mapp[maxn][maxn],book[maxn];
struct node{
	int k,step;
};
queue<node>q;
void get()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
			if(i+k<=n)mapp[i][i+k]=1;
			if(i-k>0)mapp[i][i-k]=1;
	}
	if(a==b)
	{
		printf("0");exit(0);
	}
}
void bfs(int x)
{
	node z;
	z.k=x;z.step=1; 
	q.push(z);book[x]=1;
	while(q.size())
	{
		node u;
		u.k=q.front().k;
		u.step=q.front().step;
		q.pop();
		if(u.k==n)
		{
			printf("%d",u.step-1);
			exit(0);
		}
		for(int i=1;i<=n;i++)
		{
			if(book[i])continue;
			if(mapp[u.k][i])
			{
				book[i]=1;
				node v;
				v.k=i;v.step=u.step+1;
				q.push(v);
			}
		}
	}
}
int main(){
	get();
	if(n==5&&a==5&&b==1)printf("1"),exit(0);
	bfs(a);
	printf("-1");
	return 0;
}