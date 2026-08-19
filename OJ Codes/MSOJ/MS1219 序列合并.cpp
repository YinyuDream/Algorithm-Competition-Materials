#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e5+10;
int n;
int a[maxn],b[maxn],c[maxn];
struct node{
	int sum,data;
	friend bool operator <(node x,node y){
		return x.sum>y.sum;
	}
};
priority_queue<node> q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		c[i]=2;
		node x;
		x.sum=a[i]+b[1];
		x.data=i;	
		q.push(x);
	}
	for(int i=1;i<=n;i++){
		node tmp=q.top();
		q.pop();
		printf("%d ",tmp.sum);
		tmp.sum=a[tmp.data]+b[c[tmp.data]++];
		q.push(tmp);
	}
	return 0;
}