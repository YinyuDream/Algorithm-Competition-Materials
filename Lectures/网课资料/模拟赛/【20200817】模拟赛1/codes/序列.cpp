#include<cstdio>
#include<algorithm>
const int maxn=1e6+10;
using namespace std;
int n,x,y;
int ans[maxn],a[maxn],b[maxn];
bool cmp(int a,int b)
{
	return a>b;
}
int find(int x,int opt,int l,int r)
{
	while(l<=r){
		int mid=(l+r)/2;
		if(opt==1?(x>a[mid]):(x<b[mid]))l=mid+1;
		else r=mid-1;
	}
	return l;
}
bool check()
{
	int t1=0,t2=0;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]>a[t1]||t1==0)
		a[++t1]=ans[i];
		else
		a[find(ans[i],1,1,t1)]=ans[i];
		if(ans[i]<b[t2]||t2==0)
		b[++t2]=ans[i];
		else
		b[find(ans[i],2,1,t2)]=ans[i];
	}
	return t1==x&&t2==y;
}
int main(){
	scanf("%d",&n);
	scanf("%d%d",&x,&y);
	for(int i=1;i<=n;i++)
	ans[i]=i;
	do{
		if(check()){
			puts("YES");
			for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
			return 0;
		}
	}while(next_permutation(ans+1,ans+n+1));
	puts("NO");
	return 0;
}
