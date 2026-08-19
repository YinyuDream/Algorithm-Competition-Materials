#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k;
long long a[maxn];
struct node{
	long long val;
	int pos;
	node(long long _val,int _pos){val=_val,pos=_pos;}
	friend bool operator<(node a,node b){
		return a.val>b.val;
	}
};
priority_queue<node>q;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	q.push(node(a[1],1));
	for(int i=1;i<k;i++){
		node t=q.top();
		q.pop();
		if(t.pos==n)continue;
		q.push(node(t.val-a[t.pos]+a[t.pos+1],t.pos+1));
		q.push(node(t.val+a[t.pos+1],t.pos+1));
	}
	printf("%lld",q.top().val);
	return 0;
}