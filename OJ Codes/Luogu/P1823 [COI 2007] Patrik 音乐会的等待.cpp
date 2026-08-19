#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e5+10;
int n,a[maxn];
long long sum;
int st[maxn],top;
int divide(int l,int r,int val)
{
	while(l<=r){
		int mid=(l+r)/2;
		if(st[mid]>val)l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	st[++top]=a[1];
	for(int i=2;i<=n;i++){
		int k=divide(1,top,a[i]);
		sum+=top-k+(k!=0);
		while(a[i]>st[top]&&top)top--;
		st[++top]=a[i];
	}
	printf("%lld",sum);
} 
