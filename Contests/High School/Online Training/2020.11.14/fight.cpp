#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,ans;
int a[maxn];
void work()
{
	for(int i=1;i<=n;i++)
		a[i]=i;
	do{
		int cnt=0;
		for(int i=1;i<n;i++)
			if(abs(a[i]-a[i+1])>1)cnt++;
		if(cnt<=k)ans++;
	}while(next_permutation(a+1,a+n+1));
}
int main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%d%d",&n,&k);
	work();
	printf("%d",ans); 
	return 0;
}
