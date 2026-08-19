#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,l,r=0x7fffffff,ans;
long long all,k;
int a[maxn];
int qmin[maxn],qmax[maxn],back,front,back2,front2;
bool check(int x)
{
	front=front2=back=back2=0;
	long long cnt=0;
	int l=1;
	for(int i=1;i<=n;i++)
	{
		while(front<back&&a[qmax[back-1]]<a[i])back--;
		while(front2<back2&&a[qmin[back2-1]]>a[i])back2--;
		qmax[back++]=i,qmin[back2++]=i;
		while(a[qmax[front]]-a[qmin[front2]]>x){
			l++;
			if(qmax[front]<l)front++;
			if(qmin[front2]<l)front2++;
		}
		cnt+=i-l+1;
	}
	return cnt<k;
}
int main(){
	scanf("%d%lld",&n,&k);
	all=1ll*n*(n+1)/2;
	k=all-k+1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d",l);
	return 0;
}
