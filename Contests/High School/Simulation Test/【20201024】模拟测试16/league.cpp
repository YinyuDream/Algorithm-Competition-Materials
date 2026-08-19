#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3e5+10;
int n,k,mx,l,r,t,d,ans=0X7f7f7f7f,mid,pt;
struct node{
	int to,next;
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
void add(int u,int v)
{
	edge[++k].to=v;
	edge[k].next=head[u];
	head[u]=k;
}
void dfs1(int u,int f,int len)
{
	if(len>mx)mx=len,l=u;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			dfs1(v,u,len+1);
		}
	}
}
void dfs2(int u,int f,int len)
{
	if(len>mx)mx=len,r=u;
	for(int i=head[u];i;i=edge[i].next){
		int v=edge[i].to;
		if(v!=f){
			s[v]=(i+1)/2;
			pre[v]=u;
			dfs2(v,u,len+1);
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
			dfs3(v,u,len+1);
		}
	}
}
int main(){
	freopen("league11.in","r",stdin);
	//freopen("league.out","w",stdout);
	n=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1,1,0),mx=0,dfs2(l,l,0);
	t=r;
	while(t!=l)net[pre[t]]=t,t=pre[t];
	book[l]=1;
	mid1[l]=l,mid2[r]=r;
	for(t=net[l],d=1,mid=l;t!=r;t=net[t]){
		dis1[t]=d;
		mx=0;
		dfs3(t,net[t],0);
		if(len1[pre[t]]>mx+d)len1[t]=len1[pre[t]];
		else{
			len1[t]=mx+d;
			while(max(dis1[mid],dis1[t]+mx-dis1[mid])>max(dis1[net[mid]],dis1[t]+mx-dis1[net[mid]])&&mid!=t)
			mid=net[mid];
		}
		mid1[t]=mid;
		d++;
	}
	memset(book,0,sizeof book);
	book[r]=1;
	for(t=pre[r],d=1,mid=r;t!=l;t=pre[t]){
		dis2[t]=d;
		mx=0;
		dfs3(t,pre[t],0);
		if(len2[net[t]]>mx+d)len2[t]=len2[net[t]];
		else{
			len2[t]=mx+d;
			while(max(dis2[mid],dis2[t]+mx-dis2[mid])>max(dis2[pre[mid]],dis2[t]+mx-dis2[pre[mid]])&&mid!=t)
			mid=pre[mid];
		}
		mid2[t]=mid;
		d++;
	}
	for(t=l;t!=r;t=net[t]){
		if(ans>(len1[t]+1)/2+(len2[net[t]]+1)/2+1)
		ans=(len1[t]+1)/2+(len2[net[t]]+1)/2+1,e[top=1]=s[net[t]],pt=t;
		else if(ans==(len1[t]+1)/2+(len2[net[t]]+1)/2+1)
		e[++top]=s[net[t]];
	}
	printf("%d\n%d",ans,top);
	sort(e+1,e+top+1);
	for(int i=1;i<=top;i++)
		printf(" %d",e[i]);
	puts("");
	printf("%d %d %d %d",pt,net[pt],mid1[pt],mid2[net[pt]]);
	return 0;
}
