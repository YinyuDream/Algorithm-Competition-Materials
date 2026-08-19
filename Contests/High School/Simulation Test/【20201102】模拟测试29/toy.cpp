#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,k,x,y,cnt;
long long p[maxn],ans;
int booka[maxn],bookb[maxn],a[maxn],b[maxn];
int all_like[maxn],a_like[maxn],b_like[maxn],all_not_like[maxn];
int topa,topb,topc,topd,heada=1,headb=1,headc=1;
bool cmp(int a,int b)
{
	return p[a]<p[b];
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&p[i]);
	scanf("%d",&x);
	for(int i=1;i<=x;i++)
		scanf("%d",&a[i]);
	scanf("%d",&y);
	for(int i=1;i<=y;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		booka[a[i]]++,bookb[b[i]]++;
	for(int i=1;i<=n;i++){
		if(booka[i]&&bookb[i])
		all_like[++topa]=i;
		else if(booka[i]&&!bookb[i])
		a_like[++topb]=i;
		else if(bookb[i]&&!booka[i])
		b_like[++topc]=i;
		else continue;
	}
	sort(all_like+1,all_like+topa+1,cmp);
	sort(a_like+1,a_like+topb+1,cmp);
	sort(b_like+1,b_like+topc+1,cmp);
	for(int i=1;i<=min(k,topb);i++)
		ans+=p[a_like[i]],headb++,cnt++;
	for(int i=1;i<=min(k,topc);i++)
		ans+=p[b_like[i]],headc++,cnt++;
	while(headc+heada-2<=k&&headb+heada-2<=k)
		ans+=p[all_like[heada++]],cnt++;
	while(headb+heada-2<=k)
		ans+=p[all_like[heada++]]-p[b_like[--headc]];
	while(headc+heada-2<=k)
		ans+=p[all_like[heada++]]-p[a_like[--headb]];
	while(heada<=topa){
		if(p[all_like[heada]]<p[a_like[headb-1]]+p[b_like[headc-1]])
		ans+=p[all_like[heada++]]-(p[a_like[--headb]]+p[b_like[--headc]]),cnt--;
		else break;
	}
	for(int i=1;i<=n;i++)
		if(!booka[i]&&!bookb[i])
			all_not_like[++topd]=i;
	for(int i=heada;i<=topa;i++)
		all_not_like[++topd]=all_like[i];
	for(int i=headb;i<=topb;i++)
		all_not_like[++topd]=a_like[i];
	for(int i=headc;i<=topc;i++)
		all_not_like[++topd]=b_like[i];
	sort(all_not_like+1,all_not_like+topd+1,cmp);
	for(int i=cnt+1;i<=m;i++)
		ans+=p[all_not_like[i-cnt]];
	printf("%lld",ans);
	return 0;
}
