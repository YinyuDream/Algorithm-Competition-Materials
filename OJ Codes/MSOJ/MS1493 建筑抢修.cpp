#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,sum,ans;
int a[maxn],b[maxn];
struct node{
	int a,b;
}t[maxn];
priority_queue<int>q;
bool cmp(node x,node y)
{
	return x.b<y.b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&t[i].a,&t[i].b);
	sort(t+1,t+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(sum+t[i].a<t[i].b){
			sum+=t[i].a;
			q.push(t[i].a);
			ans++;
		}
		else{
			int p=q.top();
			if(p>t[i].a){
				q.pop();
				q.push(t[i].a);
				sum=sum-p+t[i].a;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}