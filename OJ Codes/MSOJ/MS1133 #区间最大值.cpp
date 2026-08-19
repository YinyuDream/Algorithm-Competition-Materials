#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,p;
long long ans;
struct node{
	int l,r,num;
}a[maxn];
long long sum[maxn];
stack<int>s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].num),
		sum[i]=sum[i-1]+a[i].num;
	for(int i=0;i<=n+1;i++){
		while(s.size()&&a[s.top()].num>a[i].num)
		a[s.top()].r=i,s.pop();
		if(s.size())a[i].l=s.top();
		s.push(i);
	}
	for(int i=1;i<=n;i++)
		if(ans<(sum[a[i].r-1]-sum[a[i].l])*a[i].num)
		ans=(sum[a[i].r-1]-sum[a[i].l])*a[i].num,p=i;
	printf("%lld\n%d %d",ans,a[p].l+1,a[p].r-1);		
	return 0;
}
