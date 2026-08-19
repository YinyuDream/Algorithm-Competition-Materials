#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<cmath>
#include<cstdio>
#include<cctype>
#include<algorithm>
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
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
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
		else write(query(l,r,c)),puts("");
	}
	return 0;
}