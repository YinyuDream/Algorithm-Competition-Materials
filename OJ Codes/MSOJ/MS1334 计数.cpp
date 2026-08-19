#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
int T,n;
int a[maxn],st[maxn],top;
int l[maxn],r[maxn];
ll solve_max()
{
	ll ans=0;
	a[0]=a[n+1]=0x7f7f7f7f;
	top=0;
	for(int i=1;i<=n+1;i++){
		while(top&&a[st[top]]<a[i])
			r[st[top]]=i,top--;
		st[++top]=i;
	}
	top--;
	for(int i=n;i>=0;i--){
		while(top&&a[st[top]]<a[i])
			l[st[top]]=i,top--;
		st[++top]=i;
	}
	for(int i=1;i<=n;i++)
		ans+=1ll*(i-l[i])*(r[i]-i)*a[i];
	return ans;
}
ll solve_min()
{
	ll ans=0;
	a[0]=a[n+1]=-0x7f7f7f7f;
	top=0;
	for(int i=1;i<=n+1;i++){
		while(top&&a[st[top]]>a[i])
			r[st[top]]=i,top--;
		st[++top]=i;
	}
	top=0;
	for(int i=n;i>=0;i--){
		while(top&&a[st[top]]>a[i])
			l[st[top]]=i,top--;
		st[++top]=i;
	}
	for(int i=1;i<=n;i++)
		ans+=1ll*(i-l[i])*(r[i]-i)*a[i];
	return ans;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		printf("%lld\n",solve_max()-solve_min());
	}
	return 0;
}
