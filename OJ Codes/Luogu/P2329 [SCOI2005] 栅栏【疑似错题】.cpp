#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,m,sum,ans,l,r,t;
int a[maxn],b[maxn],sumb[maxn];
bool check(int mid,int x)//¿¼ÂÇµÚx¿éÄ¾²Ä
{
	if(x==0)return true;
	if(sum-t<umb[mid])return false;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>b[x])
		{
			a[i]-=b[x];
			if(a[i]<b[1])t+=a[i];
			if(check(x-1))return true;
			else{
				a[i]+=b[x];
				if(a[i]<b[1])t-=a[i];
			}
		}
	}
	return false;
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),
		sum+=a[i];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]),
		sumb[i]=sumb[i-1]+b[i];
	sort(b+1,b+m+1);
	while(sumb[m]>sum)m--;
	l=1,r=m;
	while(l<=r)
	{
		t=0;
		int mid=(l+r)/2;
		if(check(mid,mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
