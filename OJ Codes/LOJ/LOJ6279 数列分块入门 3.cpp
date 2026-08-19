#pragma GCC optimize("Ofast")
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e6+10;
int n,q;
int left[maxn],right[maxn],pos[maxn];
int lazy[maxn];
struct node{
	int id,num;
}a[maxn];
bool cmp(node x,node y){
	return x.num<y.num;
}
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,ch=getchar();
	return x*f;
}
void ycl()
{
	int t=sqrt(n);
	for(int i=1;i<=t;i++)
	left[i]=(i-1)*t+1,right[i]=i*t;
	if(right[t]!=n)
	t++,left[t]=right[t-1]+1,right[t]=n;
	for(int i=1;i<=t;i++){
		for(int j=left[i];j<=right[i];j++)
			pos[j]=i;
		sort(a+left[i],a+right[i]+1,cmp);
	}
}
void update(int l,int r,int c)
{
	if(pos[l]==pos[r]){
		for(int i=left[pos[l]];i<=right[pos[l]];i++)
			if(a[i].id>=l&&a[i].id<=r)
				a[i].num+=c;
		sort(a+left[pos[l]],a+right[pos[r]]+1,cmp);
	}else{
		for(int i=pos[l]+1;i<=pos[r]-1;i++)
			lazy[i]+=c;
		for(int i=left[pos[l]];i<=right[pos[l]];i++)
			if(a[i].id>=l&&a[i].id<=r)
				a[i].num+=c;
		for(int i=left[pos[r]];i<=right[pos[r]];i++)
			if(a[i].id>=l&&a[i].id<=r)
				a[i].num+=c;
		sort(a+left[pos[l]],a+right[pos[l]]+1,cmp);
		sort(a+left[pos[r]],a+right[pos[r]]+1,cmp);
	}
}
int query(int l,int r,int c)
{
	int ans=-0x7f7f7f7f;
	if(pos[l]==pos[r]){
		for(int i=left[pos[l]];i<=right[pos[r]];i++)
			if(a[i].num+lazy[pos[l]]<c&&a[i].id>=l&&a[i].id<=r)
				ans=max(ans,a[i].num+lazy[pos[l]]);
	}else{
		for(int i=pos[l]+1;i<=pos[r]-1;i++){
			node x;
			x.num=c-lazy[i];
			int t=lower_bound(a+left[i],a+right[i]+1,x,cmp)-a;//第一个大于等于k的下标
			if(t!=left[i])ans=max(ans,a[t-1].num+lazy[i]);
		}
		for(int i=left[pos[l]];i<=right[pos[l]];i++)
			if(a[i].num+lazy[pos[l]]<c&&a[i].id>=l&&a[i].id<=r)
				ans=max(ans,a[i].num+lazy[pos[l]]);
		for(int i=left[pos[r]];i<=right[pos[r]];i++)
			if(a[i].num+lazy[pos[r]]<c&&a[i].id>=l&&a[i].id<=r)
				ans=max(ans,a[i].num+lazy[pos[r]]);
	}
	return ans==-0x7f7f7f7f?-1:ans;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	a[i].num=read(),a[i].id=i;
	ycl();
	for(int i=1,opt,l,r,c;i<=n;i++){
		opt=read(),l=read(),r=read(),c=read();
		if(opt==0)update(l,r,c);
		else printf("%d\n",query(l,r,c));
	}
	return 0;
}