#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=3e5+10;
int n,q,x,y,mod,A,B;
struct node{
	int h,x,y,opt,id,ans;
}a[maxn];
struct BIT{
	int c[maxn];
	void clear(){
		memset(c,0,sizeof c);
	}
	void add(int pos,int val){
		for(int i=pos;i<maxn;i+=i&(-i)){
			(c[i]+=val)%=mod;
		}
	}
	int query(int pos){
		int ans=0;
		for(int i=pos;i;i-=i&(-i)){
			(ans+=c[i])%=mod;
		}
		return ans;
	}
}bit;
int qpow(int x,int y){
	if(!y)return 1;
	int c=qpow(x,y/2);
	c=1ll*c*c%p;
	if(y&1)c=1ll*c*x%p;
	return c;
}
int old[maxn],help[maxn];
void lsh_x()
{
	for(int i=1;i<=n+q;i++)
		help[i]=a[i].x;
	sort(help+1,help+n+q+1);
	int cnt=unique(help+1,help+n+q+1)-help-1;
	for(int i=1;i<=n+q;i++){
		int t=lower_bound(help+1,help+cnt+1,a[i].x)-a;
		a[i].x=t;
		old[a[i].x]=help[t];
	}
}
void lsh_y()
{
	for(int i=1;i<=n+q;i++)
		help[i]=a[i].y;
	sort(help+1,help+n+q+1);
	int cnt=unique(help+1,help+n+q+1)-help-1;
	for(int i=1;i<=n+q;i++){
		int t=lower_bound(help+1,help+cnt+1,a[i].y)-a;
		a[i].y=t;
		old[a[i].y]=help[t];
	}
}
bool cmp1(node a,node b)
{
	return a.x<b.x;
}
bool cmp2(node a,node b)
{
	return a.y<b.y;
}
int main(){
	scanf("%d%d%d%d%d%d%d",&n,&q,&x,&y,&mod,&A,&B);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].h,&a[i].x,&a[i].y),a[i].opt=1;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&a[i+n].x,&a[i+n].y),a[i].opt=2,a[i].id=i;
	}
	bit.clear();
	lshy();
	sort(a+1,a+n+q+1,cmp1);
	for(int i=1;i<=n+q;i++){
		if(a[i].opt==1){
			bit.add(a[i].h*qpow(a[i].x)*qpow());
		}else{
			a[i].ans+=query()
		}
	}
	for(int i=n+q;i>=1;i--){
		if(a[i].opt==1){
			
		}else{
			
		}
	}
	return 0;
