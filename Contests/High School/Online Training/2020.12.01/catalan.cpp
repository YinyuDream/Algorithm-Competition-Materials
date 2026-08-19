#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const ll p=998244353;
int n,m;
int a[maxn],b[maxn];
namespace subtask1{
	ll f[maxn];
	void work()
	{
		f[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				(f[i]+=f[j-1]*f[i-j])%=p;
		printf("%lld\n",f[n]);
	}
}
namespace subtask2{
	int st[maxn],c[maxn],pos[maxn],num,top,ans;
	bool check()
	{
		for(int i=1;i<=n;i++)
			pos[c[i]]=i;
		for(int i=1;i<=m;i++)
			if(pos[a[i]]>pos[b[i]])
				return false;
		return true;
	}
	void dfs(int now)
	{
		if(now==n+1&&!top){
			if(check())ans++;
			return ;
		}
		if(top){
			int t=st[top];
			c[++num]=t,top--,dfs(now),st[++top]=t,num--;
		}
		if(now<=n)st[++top]=now,dfs(now+1),top--;
	}
	void work(){
		dfs(1);
		printf("%d",ans);
	}
}
int main(){
	freopen("catalan.in","r",stdin);
	freopen("catalan.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a[i],&b[i]);
	if(m==0)subtask1::work();
	else subtask2::work();
	return 0;
}
