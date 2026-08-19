#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1e5+10;
int n;
double d1,C,d2,P,ans,v;
double d[maxn],p[maxn];
struct node{
	double p,c;
	node(double _p,double _c){
		p=_p,c=_c;
	}
};
deque<node>q;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	scanf("%lf%lf%lf%lf%d",&d1,&C,&d2,&P,&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&d[i],&p[i]);
	d[n+1]=d1;
	for(int i=1;i<=n+1;i++)
		if(C*d2<d[i]-d[i-1]){
			puts("No Solution");
			return 0;
		}
	q.push_back(node(P,C));
	v=C;
	for(int i=1;i<=n+1;i++)
	{
		double t=d[i]-d[i-1];
		while(q.size()&&t-q.front().c*d2>=0){
			t-=q.front().c*d2;
			ans+=q.front().c*q.front().p;
			v-=q.front().c;
			q.pop_front();
		}
		q.front().c-=t/d2;
		ans+=q.front().p*(t/d2);
		v-=t/d2;
		if(i==n+1)break;
		while(q.size()&&q.back().p>p[i]){
			v-=q.back().c;
			q.pop_back();	
		}
		q.push_back(node(p[i],C-v));
		v=C;
	}
	printf("%.2f",ans);
	return 0;
}
