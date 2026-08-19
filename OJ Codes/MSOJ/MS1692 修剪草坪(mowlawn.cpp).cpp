#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k;
long long a[maxn],sum[maxn],f[maxn][2];
deque<pair<int,long long> >q;
int main(){
	//freopen("mowlawn.in","r",stdin);
	//freopen("mowlawn.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),
		sum[i]=sum[i-1]+a[i];
	q.push_back(make_pair(0,0));
	for(int i=1;i<=n;i++){
		if(q.size()&&q.front().first<max(i-k,0))q.pop_front();
		f[i][1]=q.front().second+sum[i];
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		while(q.size()&&q.back().second<f[i][0]-sum[i])q.pop_back();
		q.push_back(make_pair(i,f[i][0]-sum[i]));
	}
	printf("%lld",max(f[n][1],f[n][0]));
	return 0;
}