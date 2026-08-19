#include<cmath>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e5+10,N=1e3+10;
int n,m,a[maxn];
int pos[maxn],sum[N],book[N],l[N],r[N];
void pre()
{
	int block=sqrt(n);
	for(int i=1;i<=block;i++)
		l[i]=(i-1)*block+1,r[i]=i*block;
	if(r[block]!=n)
		block++,l[block]=r[block-1]+1,r[block]=n;
	for(int i=1;i<=block;i++)
		for(int j=l[i];j<=r[i];j++)
		{
			pos[j]=i,sum[i]+=a[j];
			if(a[j]!=1)
			book[i]++;
		}	
}
void change(int L,int R)
{
	if(pos[L]==pos[R])
	{
		for(int i=L;i<=R;i++)
		{
			int t=sqrt(a[i]);
			if(t==1&&a[i]!=1)
			book[pos[L]]--;
			sum[pos[L]]-=(a[i]-t);
			a[i]=t;
		}
	}
	else
	{
		for(int i=L;i<=r[pos[L]];i++)
		{
			int t=sqrt(a[i]);
			if(t==1&&a[i]!=1)
			book[pos[L]]--;
			sum[pos[L]]-=(a[i]-t);
			a[i]=t;
		}
		for(int i=l[pos[R]];i<=R;i++)
		{
			int t=sqrt(a[i]);
			if(t==1&&a[i]!=1)
			book[pos[R]]--;
			sum[pos[R]]-=(a[i]-t);
			a[i]=t;
		}
		for(int i=pos[L]+1;i<=pos[R]-1;i++)
		{
			if(book[i]==0)
			continue;
			for(int j=l[i];j<=r[i];j++)
			{
				int t=sqrt(a[j]);
				if(t==1&&a[j]!=1)
				book[i]--;
				sum[i]-=(a[j]-t);
				a[j]=t;
			}
		}
	}
}
int query(int L,int R)
{
	int ans=0;
	if(pos[L]==pos[R])
	{
		for(int i=L;i<=R;i++)
		ans+=a[i];
	}
	else
	{
		for(int i=L;i<=r[pos[L]];i++)
		ans+=a[i];
		for(int i=l[pos[R]];i<=R;i++)
		ans+=a[i];
		for(int i=pos[L]+1;i<=pos[R]-1;i++)
		ans+=sum[i];
	}
	return ans;
}
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	pre();
	for(int i=1;i<=n;i++)
	{
		int opt,L,R,c;
		scanf("%lld%lld%lld%lld",&opt,&L,&R,&c);
		if(L>R)swap(L,R);
		if(opt==0){
			change(L,R);
		}else{
			printf("%lld\n",query(L,R));
		}
	}
	return 0;
}
