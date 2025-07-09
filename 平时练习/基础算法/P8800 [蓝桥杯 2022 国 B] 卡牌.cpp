#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,m,ans;
struct card{
	int a,b;
}t[maxn];
int minx[maxn];
bool cmp(card p,card q)
{
	return p.a<q.a;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&t[i].a);
	for(int i=1;i<=n;i++)
		scanf("%lld",&t[i].b);
	t[n+1].a=0x7f7f7f7f7f7f7f7fll;	
	sort(t+1,t+n+2,cmp);
	ans=t[1].a,minx[1]=t[1].b;
	for(int i=2;i<=n;i++)
		minx[i]=min(minx[i-1],t[i].b);
	for(int i=1;i<=n;i++)
		if(t[i].a<t[i+1].a){
			int delta=t[i+1].a-t[i].a;
			if(t[i+1].a>minx[i]){
				if((minx[i]-t[i].a)*i<=m){
					m-=(minx[i]-t[i].a)*i;
					ans+=minx[i]-t[i].a;
				}else{
					ans+=m/i;
				}
				break;
			}else{
				if(delta*i<=m){
					m-=delta*i;
					ans+=delta;
				}else{
					ans+=m/i;
					break;
				}
			}
		}
	printf("%lld",ans);
	return 0;
}