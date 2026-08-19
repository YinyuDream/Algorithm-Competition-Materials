#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,k,ans,cnt;
struct node{
	int x,y,num;
}p[maxn];
bool cmp(node a,node b)
{
	return a.num>b.num;
}
int main(){
	//freopen("peanuts.in","r",stdin);
	//freopen("peanuts.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,num;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&num);
			if(num){
				p[++cnt].x=i;
				p[cnt].y=j;
				p[cnt].num=num;
			}
		}
	sort(p+1,p+cnt+1,cmp);
	p[0].y=p[1].y;
	for(int i=0;i<cnt;i++){
		int d=abs(p[i+1].x-p[i].x)+abs(p[i+1].y-p[i].y);
		if(d+p[i+1].x+1<=k)ans+=p[i+1].num,k-=d+1;
		else break;
	}
	printf("%d",ans);
	return 0;
}