#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3e4+10;
int n;
long long ans;
int a[maxn],l[maxn],r[maxn],tree[maxn],b[maxn];
void lsh()
{
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	sort(b+1,b+n+1);
	int m=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++)
	a[i]=lower_bound(b+1,b+m+1,a[i])-b;
}
inline int lowbit(int x)
{
	return x&-x;
}
void update(int x,int val)
{
	for(int i=x;i<=n;i+=lowbit(i))tree[i]+=val;
}
int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))ans+=tree[i];
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	lsh();
	for(int i=1;i<=n;i++)
	l[i]=query(a[i]-1),update(a[i],1);
	memset(tree,0,sizeof tree);
	for(int i=n;i>=1;i--)
	r[i]=(query(n)-query(a[i])),update(a[i],1);
	for(int i=1;i<=n;i++)
		ans+=l[i]*r[i];
	printf("%lld",ans);
	return 0;
}
