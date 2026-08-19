#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,mx;
int a[maxn],book[maxn],sum[maxn],ans[maxn];
int main(){
	//freopen("end.in","r",stdin);
	//freopen("end.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		book[a[i]]++;
		mx=max(mx,a[i]);
	}
	for(int i=1;i<=mx;i++)
		for(int j=1;j*i<=mx;j++)
			if(book[j*i])sum[i]+=book[j*i];
	for(int i=mx;i>=1;i--)
		if(sum[i]){
			for(int j=sum[i];j>=1;j--)
			if(!ans[j])ans[j]=i;
			else break;
		}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}