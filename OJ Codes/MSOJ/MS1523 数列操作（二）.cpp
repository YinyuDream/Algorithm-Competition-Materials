#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int m,top;
long long a[maxn],num[maxn],sum[maxn],max_val[maxn],max_sum[maxn],max_lsum[maxn];
int main(){
	max_sum[0]=max_val[0]=max_lsum[0]=-0x7f7f7f7f7f7f7f7fll;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			long long x;
			scanf("%lld",&x);
			top++;
			num[top]=x;
			sum[top]=sum[top-1]+x;
			max_val[top]=max(max_val[top-1],x);
			max_sum[top]=max(max_sum[top-1],sum[top]);
			max_lsum[top]=max(max_lsum[top-1]+x,x);
		}
		else if(opt==2)printf("%lld\n",max_val[top]);
		else if(opt==3){if(top)top--;}
		else if(opt==4)printf("%lld\n",max_sum[top]);
		else printf("%lld\n",max_lsum[top]);
	}
	return 0;
}
