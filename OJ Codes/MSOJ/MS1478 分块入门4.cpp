#include<cstdio>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e6+10;
int n,t;
int l[maxn],r[maxn],pos[maxn],lazy[maxn],sum[maxn],a[maxn];
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')x=x*10+(ch-'0'),ch=getchar();
	return x*f;
}
void ycl()
{
	for(int i=1;i<=t;i++)l[i]=(i-1)*t+1,r[i]=i*t;
	if(r[t]<n)t++,l[t]=r[t-1]+1,r[t]=n;
	for(int i=1;i<=t;i++)
		for(int j=l[i];j<=r[i];j++)
			pos[j]=i,sum[i]+=a[j];
}
void update(int left,int right,int c)
{
	if(pos[left]==pos[right]){
		for(int i=left;i<=right;i++)a[i]+=c;
		sum[pos[left]]+=(right-left+1)*c;
	}else{
		for(int i=pos[left]+1;i<=pos[right]-1;i++)
			lazy[i]+=c;
		for(int i=left;i<=r[pos[left]];i++)
			a[i]+=c,sum[pos[left]]+=c;
		for(int i=l[pos[right]];i<=right;i++)
			a[i]+=c,sum[pos[right]]+=c;
	}
}
long long getsum(int L,int R,int ct)
{
	long long x=0;
	if(pos[L]==pos[R]){
		for(int i=L;i<=R;i++)x=(x+a[i]%(ct+1));
		x=(x+(lazy[pos[L]]*(R-L+1)))%(ct+1);
		return x%(ct+1);
	}else{
		for(int i=pos[L]+1;i<=pos[R]-1;i++)
			x=(x+(sum[i]+lazy[i]*(r[pos[i]]-l[pos[i]]+1)))%(ct+1);
		for(int i=L;i<=r[pos[L]];i++)
			x=(x+a[i])%(ct+1);
		x=(x+(lazy[pos[L]]*(r[pos[L]]-L+1)))%(ct+1);
		for(int i=l[pos[R]];i<=R;i++)
			x=(x+a[i])%(ct+1);
		x=(x+(lazy[pos[R]]*(R-l[pos[R]]+1)))%(ct+1);
		return x%(ct+1);
	}
}
main(){
	n=read();t=sqrt(n);
	for(int i=1;i<=n;i++)a[i]=read();
	ycl();
	for(int i=1,opt,L,R,c;i<=n;i++){
		opt=read(),L=read(),R=read(),c=read();
		if(!opt)update(L,R,c);
		else printf("%lld\n",getsum(L,R,c)%(c+1));
	}
	return 0;
}
