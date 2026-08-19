#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,lmax,sum,ans=0x7f7f7f7f;
int w[maxn],h[maxn];
struct node{
	int h,w;
	node(int _h,int _w)
	{
		h=_h,w=_w;
	}
	friend bool operator<(node a,node b)
	{
		return a.w-a.h<b.w-b.h;
	}
};
priority_queue<node>q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&h[i]),
		lmax=max(lmax,max(w[i],h[i])),
		sum+=w[i];
	for(int i=1;i<=lmax;i++)
	{
		while(q.size())q.pop();
		int t=sum,cnt=0,flag=0;
		for(int j=1;j<=n;j++)
		{
			if(h[j]>i&&w[j]>i){
				flag=-1;break;
			}
			if(h[j]>i){
				t=t-w[i]+h[i];
				cnt++;
				if(cnt>n/2){
					flag=-1;
					break;
				}
			}
			else if(h[j]<=i&&w[j]<=i)
			q.push(node(h[j],w[j]));
		}
		while(q.size()&&q.top().w-q.top().h>0&&cnt<=n/2)
		t=t-q.top().w+q.top().h,q.pop(),cnt++;
		if(flag!=-1)
		ans=min(ans,t*i);
	}
	printf("%d",ans);
	return 0;
}
