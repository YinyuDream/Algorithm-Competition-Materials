#include<cstdio>
const int maxn=1e5+10;
using namespace std;
int k,n;
long long a[maxn],sum;
double t;
bool cheak(long long x){
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=a[i]/x;
	return ans>=(long long)k;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lf",&t),a[i]=t*100,sum+=a[i];
	long long left=1,right=sum;
	while(left<=right){
		long long mid=(left+right)/2;
		if(cheak(mid))left=mid+1;
		else right=mid-1;
	}
	printf("%.2f",(double)right/100);
	return 0;
}
