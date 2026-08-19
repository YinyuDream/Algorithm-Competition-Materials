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
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef vector<int>::iterator IT;
const int maxn=2e5+10;
int T,n;
vector<int>bkx[maxn],bky[maxn];
struct node{
	int x,y;
}p[maxn];
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0,sign=1;
    while(!(ch>='0'&&ch<='9')){
    	if(ch=='-')sign=-sign;
    	ch=nc();
    }
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum*sign;
}
bool cmp(node a,node b)
{
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}
void lsh()
{
	static int help[maxn];
	for(int i=1;i<=n;i++)
		help[i]=p[i].x;
	sort(help+1,help+n+1);
	int cnt=unique(help+1,help+n+1)-help-1;
	for(int i=cnt;i>=2;i--)
		if(help[i-1]+1!=help[i])
			help[++cnt]=help[i-1]+1;
	sort(help+1,help+cnt+1);
	for(int i=1;i<=n;i++)
		p[i].x=lower_bound(help+1,help+cnt+1,p[i].x)-help;
	for(int i=1;i<=n;i++)
		help[i]=p[i].y;
	sort(help+1,help+n+1);
	cnt=unique(help+1,help+n+1)-help-1;
	for(int i=cnt;i>=2;i--)
		if(help[i-1]+1!=help[i])
			help[++cnt]=help[i-1]+1;
	sort(help+1,help+cnt+1);
	for(int i=1;i<=n;i++)
		p[i].y=lower_bound(help+1,help+cnt+1,p[i].y)-help;
}
bool work(int x,int y,int face,int limit)
{
	int cnt=0;
	while(cnt<=limit)
	{
		if(face==0){
			IT t=upper_bound(bky[y].begin(),bky[y].end(),x);
			if(t==bky[y].end())return true;
			x=*t-1;
			face++;
		}else if(face==1){
			IT t=upper_bound(bkx[x].begin(),bkx[x].end(),y);
			if(t==bkx[x].end())return true;
			y=*t-1;
			face++;
		}else if(face==2){
			IT t=lower_bound(bky[y].begin(),bky[y].end(),x);
			if(t==bky[y].begin())return true;
			x=*(t-1)+1;
			face++;
		}else{
			IT t=lower_bound(bkx[x].begin(),bkx[x].end(),y);
			if(t==bkx[x].begin())return true;
			y=*(t-1)+1;
			face=0;
		}
		cnt++;
	}
	return false;
}
int main(){
	//freopen("maze.in","r",stdin);
	T=read();
	while(T--){
		int x,y,dx,dy,face;
		x=read(),y=read(),dx=read(),dy=read(),n=read();
		if(dx==1&&dy==0)face=0;
		else if(dx==0&&dy==1)face=1;
		else if(dx==-1&&dy==0)face=2;
		else face=3;
		for(int i=1;i<=n;i++)
			p[i].x=read(),p[i].y=read();
		p[++n].x=x,p[n].y=y;
		lsh();
		sort(p+1,p+n,cmp);
		for(int i=0;i<maxn;i++){
			bkx[i].clear();
			bky[i].clear();
		}
		for(int i=1;i<n;i++){
			bkx[p[i].x].push_back(p[i].y);
			bky[p[i].y].push_back(p[i].x);
		}
		if(work(p[n].x,p[n].y,face,(n-1)*4))puts("YES");
		else puts("NO");
	}
	return 0;
}