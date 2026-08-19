#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,ans;
struct node{
	int a,b;
}q[maxn];
void work(int lim)
{
	for(int i=1;i<=n;i++){
		
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&q[i].a,&q[i].b);
	for(int i=1;i<=n;i++)
		ans=max(ans,work(q[i].b));
	printf("%d",ans);
	return 0;
}
