#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int T,n;
int head=1,net[maxn];
double d[maxn],r[maxn],v[maxn],l[maxn],t,pt;
bool check()
{
	int p=-1;
	double mx=0x7f7f7f7f;
	for(int i=head;net[i];i=net[i]){
		if(v[i]-v[net[i]]>0&&(r[i]-l[net[i]])/(v[i]-v[net[i]])<mx){
			mx=(r[i]-l[net[i]])/(v[i]-v[net[i]]);
			p=i;
		}
	}
	if(p==-1)return false;
	if(pt-mx*v[head]<=0){
		t+=pt/v[head];
		pt-=mx*v[head];
		
		return false;
	}
	t+=mx;
	for(int i=head;i;i=net[i]){
		l[i]-=mx*v[i];
		r[i]-=mx*v[i];
	}
	pt-=mx*v[head];
	d[p]+=d[net[p]];
	v[p]=v[net[p]];
	r[p]=r[net[p]];
	net[p]=net[net[p]];	
	return true;
}
int main(){
	freopen("cruise.in","r",stdin);
	freopen("cruise.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		t=0;
		scanf("%d",&n);
		for(int i=1;i<=n+1;i++)
			scanf("%lf",&d[i]);
		for(int i=1;i<=n+1;i++)
			scanf("%lf",&r[i]);
		for(int i=1;i<=n+1;i++)
			scanf("%lf",&v[i]);
		for(int i=1;i<=n+1;i++)
			l[i]=r[i]+d[i];
		for(int i=1;i<=n;i++)
			net[i]=i+1;
		pt=r[head];
		while(check());
		if(pt<=0)printf("%.3f\n",t);
		else printf("%.3f\n",t+pt/v[head]);
	}
	return 0;
}
