#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n=1,t;
struct node{
	int id,t,last,val;
	friend bool operator<(node a,node b){
		if(a.val!=b.val)return a.val<b.val;
		return a.t>b.t;
	}
}a[maxn];
priority_queue<node>q;
int main(){
	while(scanf("%d%d%d%d",&a[n].id,&a[n].t,&a[n].last,&a[n].val)!=EOF)n++;
	a[n].t=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		while(q.size()&&t+q.top().last<=a[i].t){
			printf("%d %d\n",q.top().id,t+q.top().last);
			t+=q.top().last;
			q.pop();
		}
		if(q.size()){
			node tp=q.top();
			q.pop();
			tp.last-=a[i].t-t;
			q.push(tp);
		}
		t=a[i].t;
		q.push(a[i]);
	}
	return 0;
}
