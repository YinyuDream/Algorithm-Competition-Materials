#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n,R,G,l=1,r,ans;
int a[maxn];
bool work(int d,int l,int r,int &x,int &y)
{
	int len=a[r]-a[l]+1;
	if(len<=d){
		if(x>0)x--;
		else if(y>0)y--;
		else return false;
	}else if(len>d&&len<=d*2){
		if(y>0)y--;
		else if(x>1)x-=2;
		else return false;
	}else{
		int last=a[l]-1;
		for(int i=l;i<=r;i++){
			if(a[i]<=last)continue;
			if(y>0){
				last=a[i]+2*d-1;
				y--;
			}else if(x>0){
				last=a[i]+d-1;
				x--;
			}else{
				return false;
			}
		}
	}
	return true;
}
bool check(int x)
{
	int last=1,p=R,q=G;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]+1>2*x){
			if(!work(x,last,i-1,p,q))return false;
			last=i;
		}
	}
	if(!work(x,last,n,p,q))return false;
	return true;
}
int main(){
	freopen("light.in","r",stdin);
	freopen("light.out","w",stdout);
	scanf("%d%d%d",&n,&R,&G);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	r=a[n]-a[1];
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}
