#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,k,a[maxn],sum[maxn],ans[maxn],top;
inline bool check(int x)
{
	for(int i=0;i<=n;i++)
	{
		bool book=0;
		int ans_z=sum[i]>x?0:sum[i];
		for(int j=i;j<=n;j++)
		{
			int ans_y=(sum[j]-sum[i])>x?0:(sum[j]-sum[i]);
			if(ans_y>=ans_z){
				book=1;break;
			}
		}
		if(book==0)return true;
	}
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		if(check(i))
			ans[++top]=i;
	printf("%d\n",top);
	for(int i=1;i<=top;i++)
		printf("%d ",ans[i]);
}