#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m;
struct _node{
	int x,y,wt,used;
}a[maxn];
struct node{
	int to,next,wt;
}edge[maxn];
int head[maxn],cnt;
void add(int u,int v,int w){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	edge[cnt].wt=w;
	head[u]=cnt;
}
bool operator <(const _node &u,const _node &v){
	return u.wt<v.wt;
}
int bel[maxn];
int find(int x)
{
	return bel[x]==x?x:bel[x]=find(bel[x]);
}
int mx1[maxn],lmx1[maxn],mx2[maxn],lmx2[maxn];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;

}
void dfs1(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].to;
		if(v==f)continue;
		if(edge[i].wt>mx1[u]){
			mx1[v]=edge[i].wt;
			lmx1[v]=mx1[u];
		}else if(edge[i].wt>lmx1[u]){
			mx1[v]=mx1[u];
			lmx1[v]=edge[i].wt;
		}else{
			mx1[v]=mx1[u];
			lmx1[v]=lmx1[u];
		}
		dfs1(v,u);
	}
}
void dfs2(int u,int f)
{
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v==f)continue;
		if(edge[i].wt>mx2[u]){
			mx2[v]=edge[i].wt;
			lmx2[v]=mx2[u];
		}else if(edge[i].wt>lmx2[u]){
			mx2[v]=mx2[u];
			lmx2[v]=edge[i].wt;
		}else{
			mx2[v]=mx2[u];
			lmx2[v]=lmx2[u];
		}
		dfs2(v,u);
	}
}
int find_max(int _a,int _b,int _c,int _d,int _e)
{
	int _num[5]={_a,_b,_c,_d,_e};
	sort(_num,_num+5);
	return _num[3]+_num[4];
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
		a[i].x=read(),a[i].y=read(),a[i].wt=read();
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++) 
		bel[i]=i;
	for(int i=1;i<=m;i++){
		int x=find(a[i].x),y=find(a[i].y);
		if(x!=y){
			bel[x]=y;
			add(a[i].x,a[i].y,a[i].wt);
			add(a[i].y,a[i].x,a[i].wt);
			a[i].used=1;
		}
	}
	
	dfs1(1,1);
	dfs2(n,n);
	int ans=mx1[n]+lmx1[n];
	for(int i=1;i<=m;i++){
		if(a[i].used==0){
			int num1=find_max(a[i].wt,mx1[a[i].x],lmx1[a[i].x],mx2[a[i].y],lmx2[a[i].y]);
			int num2=find_max(a[i].wt,mx1[a[i].y],lmx1[a[i].y],mx2[a[i].x],lmx2[a[i].x]);
			ans=min(ans,min(num1,num2));
		}
	}
	cout<<ans<<endl;
	return 0;
}