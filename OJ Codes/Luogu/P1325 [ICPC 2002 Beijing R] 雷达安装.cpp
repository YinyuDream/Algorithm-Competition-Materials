#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,d,ans=1,t;
struct node{
	int l,r;
}a[maxn];
bool cmp(node a,node b)
{
	if(a.r!=b.r)return a.r<b.r;
	else return a.l<b.l;
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		if(y>d){
			printf("-1");return 0;
		}
		int L=x-sqrt(d*d-y*y),R=x+sqrt(d*d-y*y);
		a[i].l=L,a[i].r=R;
	}
	sort(a+1,a+n+1,cmp);
	t=a[1].r;
	for(int i=2;i<=n;i++){
		if(a[i].l>t){
			t=a[i].r;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
} 