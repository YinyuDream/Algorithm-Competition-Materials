#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int a[maxn],n,k,minx=0x7f7f7f7f,sum,top;
int s[maxn],e[maxn];
bool cheak(int x)
{
	int temp=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x)return false;
		temp+=a[i];
		if(temp>x)cnt++,temp=a[i];
	}
	if(cnt>x)return true;
	else return false;
}
void pt(int r)
{
	int temp=0,la=n;
	for(int i=n;i>=1;i--){
		temp+=a[i];
		if(temp>r)s[++top]=i+1,e[top]=la,la=i,temp=a[i];
	}
	for(int i=top;i>=1;i--)
		printf("%d %d\n",s[i],e[i]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]),minx=min(minx,a[i]),sum+=a[i];
	int left=minx,right=sum;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(cheak(mid))left=mid+1;
		else right=mid-1;
	}
	pt(right);
	return 0;
}
