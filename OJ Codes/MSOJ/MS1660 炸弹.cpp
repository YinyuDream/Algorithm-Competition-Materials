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
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,l,r;
int a[maxn];
char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
int read()
{
	int x=0;
	char ch=nc();
	while(ch<'0'||ch>'9')ch=nc();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=nc();
	return x; 
}
bool check(int x,int pos)
{
	int l=pos,r=pos;
	while(x){
		int mx=a[r]+x,mn=a[l]-x;
		while(l>=1&&a[l]>=mn)l--;
		while(r<=n&&a[r]<=mx)r++;
		l++,r--;
		if(l==1&&r==n)return true;
		x=2*x/3;
	}
	return false;
}
int solve(int p)
{
	int _l=0,_r=a[n],num=0;
	while(_l<=_r){
		int mid=(_l+_r)/2;
		if(check(mid,p))_r=mid-1,num=mid;
		else _l=mid+1;
	}
	return num;
}
int main(){
	//freopen("bomb.in","r",stdin);
	//freopen("bomb.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r){
		int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
		if(solve(lmid)<=solve(rmid))r=rmid-1;
		else l=lmid+1;
	}
	printf("%d",solve(l));
	return 0;
}