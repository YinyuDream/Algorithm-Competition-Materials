#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,k;
int ans[maxn],sum[maxn];
struct node{
	int a,b,c,cnt,ans;
}q[maxn],t[maxn];
bool operator!=(const node &x,const node &y)
{
	return x.a!=y.a||x.b!=y.b||x.c!=y.c;
}
bool cmp(node x,node y)
{
	if(x.a!=y.a)return x.a<y.a;
	if(x.b!=y.b)return x.b<y.b;
	return x.c<y.c;
}
bool cmps(node x,node y)
{
	if(x.b!=y.b)return x.b<y.b;
	return x.c<y.c;
}
void update(int x,int y)
{
	for(int i=x;i<=k;i+=i&(-i))
		sum[i]+=y;
}
int query(int x)
{
	int tot=0;
	for(int i=x;i;i-=i&(-i))
		tot+=sum[i];
	return tot;
}
void cdq(int l,int r)
{
	if(l==r)return ;
	int mid=(l+r)/2;
	cdq(l,mid),cdq(mid+1,r);
	sort(t+l,t+mid+1,cmps);
	sort(t+mid+1,t+r+1,cmps);
	int j=l;
	for(int i=mid+1;i<=r;i++){
		while(t[j].b<=t[i].b&&j<=mid){
			update(t[j].c,t[j].cnt);
			j++;
		}
		t[i].ans+=query(t[i].c);
	}
	for(int i=l;i<j;i++)
		update(t[i].c,-t[i].cnt);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&q[i].a,&q[i].b,&q[i].c);
	sort(q+1,q+n+1,cmp);
	for(int i=1,top=0;i<=n;i++){
		top++;
		if(q[i]!=q[i+1]){
			t[++m]=q[i];
			t[m].cnt=top;
			top=0;
		}
	}
	cdq(1,m);
	for(int i=1;i<=m;i++)
		ans[t[i].cnt+t[i].ans-1]+=t[i].cnt;
	for(int i=0;i<n;i++)
		printf("%d\n",ans[i]);
	return 0;
}