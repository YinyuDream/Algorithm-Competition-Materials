#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,k,mx,l,r,t,d,ans=0X7f7f7f7f,mid,pt,dist;
struct node{
	int to,next,wt;
}edge[maxn*2];
int head[maxn];
int pre[maxn],net[maxn],len1[maxn],len2[maxn],book[maxn],s[maxn],dis1[maxn],dis2[maxn],mid1[maxn],mid2[maxn];
int e[maxn],top;
int read()
{
	int x=0,sign=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')sign=-sign;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,ch=getchar();
	return x*sign;
}
void add(int u,int v,int w)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	edge[k].wt=w;
	head[u]=k;
}
void dfs1(int u,int f,int len)
{
	if(len>mx)mx=len,l=u;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			dfs1(v,u,len+edge[i].wt);
		}
	}
}
void dfs2(int u,int f,int len)
{
	if(len>mx)mx=len,r=u;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			s[v]=edge[i].wt;
			pre[v]=u;
			dfs2(v,u,len+edge[i].wt);
		}
	}
}
void dfs3(int u,int f,int len)
{
	book[u]=1;
	if(len>mx)mx=len;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f&&!book[v]){
			dfs3(v,u,len+edge[i].wt);
		}
	}
}
int main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dfs1(1,1,0),mx=0,dfs2(l,l,0),dist=mx;
	t=r;
	while(t!=l)net[pre[t]]=t,t=pre[t];
	book[l]=1;
	mid1[l]=l,mid2[r]=r;
	for(t=net[l],d=s[net[l]],mid=l;t;t=net[t]){
		dis1[t]=d;
		mx=0;
		dfs3(t,net[t],0);
		if(len1[pre[t]]>=mx+d)len1[t]=len1[pre[t]],mid1[t]=mid1[pre[t]];
		else{
			len1[t]=mx+d;
			while(max(dis1[mid],dis1[t]+mx-dis1[mid])>max(dis1[net[mid]],dis1[t]+mx-dis1[net[mid]])&&mid!=t)
			mid=net[mid];
			mid1[t]=max(dis1[mid],dis1[t]+mx-dis1[mid]);
		}
		
		d+=s[net[t]];
		if(t==r)break;
	}
	memset(book,0,sizeof book);
	book[r]=1;
	for(t=pre[r],d=s[r],mid=r;t;t=pre[t]){
		dis2[t]=d;
		mx=0;
		dfs3(t,pre[t],0);
		if(len2[net[t]]>=mx+d)len2[t]=len2[net[t]],mid2[t]=mid2[net[t]];
		else{
			len2[t]=mx+d;
			while(max(dis2[mid],dis2[t]+mx-dis2[mid])>max(dis2[pre[mid]],dis2[t]+mx-dis2[pre[mid]])&&mid!=t)
			mid=pre[mid];
			mid2[t]=max(dis2[mid],dis2[t]+mx-dis2[mid]);
		}
		d+=s[t];
		if(t==l)break;
	}
	mid1[l]=mid2[r]=0;
	for(t=l;t!=r;t=net[t]){
		if(ans>max(mid1[t]+mid2[net[t]]+s[net[t]],max(len1[t],len2[net[t]])))
		ans=max(mid1[t]+mid2[net[t]]+s[net[t]],max(len1[t],len2[net[t]]));
	}
	printf("%d",ans);
	return 0;
}
