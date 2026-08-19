#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n;
double d1,C,d2,P,ans,v;
double d[maxn],p[maxn];
struct point{
	double d,p;
}qp[maxn];
struct node{
	double p,c;
	node(double _p,double _c){
		p=_p,c=_c;
	}
};
bool cmp(point a,point b)
{
	return a.d<b.d;
}
deque<node>q;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	scanf("%lf%lf%lf%lf%d",&d1,&C,&d2,&P,&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&qp[i].d,&qp[i].p);
	sort(qp+1,qp+n+1,cmp);
	qp[n+1].d=d1;
	for(int i=1;i<=n+1;i++)
		if(C*d2<qp[i].d-qp[i-1].d){
			puts("No Solution");
			return 0;
		}
	q.push_back(node(P,C));
	v=C;
	for(int i=1;i<=n+1;i++)
	{
		double t=qp[i].d-qp[i-1].d;
		while(q.size()&&t-q.front().c*d2>0){
			t-=q.front().c*d2;
			ans+=q.front().c*q.front().p;
			v-=q.front().c;
			q.pop_front();
		}
		q.front().c-=t/d2;
		ans+=q.front().p*(t/d2);
		v-=t/d2;
		if(i==n+1)break;
		while(q.size()&&q.back().p>qp[i].p){
			v-=q.back().c;
			q.pop_back();	
		}
		q.push_back(node(qp[i].p,C-v));
		v=C;
	}
	printf("%.2f",ans);
	return 0;
}