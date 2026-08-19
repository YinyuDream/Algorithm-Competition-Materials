#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=23;
const int p=998244353;
int type,ans;
ll n,k;
namespace subtask1{
	int f[1<<maxn],bit_cnt[1<<maxn],book[1<<maxn],c[maxn+10],num,cnt;
	int q[1<<maxn],head=1,tail;
	void init(){
		char s[25];
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0;i<len;i++)
			num+=(s[i]-'0')<<(len-i-1),cnt+=(s[i]=='1');
		c[1]=1;
		for(int i=2;i<=n+1;i++)
			c[i]=c[i-1]+(1<<(i-1));
	}
	bool check(int num,int l,int r)
	{
		for(int i=l,col=1;i<=r;i++,col^=1)
			if(((num>>i)&1)!=col)
				return false;
		return true;
	}
	void bfs()
	{
		f[num]=1;
		q[++tail]=num;
		book[num]=1;
		while(head<=tail){
			int x=q[head++];
			for(int l=0;l<n;l++){
				for(int r=l;r<n;r+=2){
					if(check(x,l,r)){
						(f[x^(c[r+1]-c[l])]+=f[x])%=p;
						if(!book[x^(c[r+1]-c[l])])
						q[++tail]=x^(c[r+1]-c[l]);
						book[x^(c[r+1]-c[l])]=1;
					}else{
						break;
					}
				}
			}		
		}
	}
	void work()
	{
		init();
		for(int i=1;i<(1<<n);i++)
			bit_cnt[i]=bit_cnt[i-(i&(-i))]+1; 
		bfs();
		for(int i=0;i<(1<<n);i++)
			if(bit_cnt[i]==cnt-k)
				(ans+=f[i])%=p;
		printf("%d",ans);
	}
}
namespace subtask2{
	ll f[maxn*20][maxn*20],jc[maxn*20],inv[maxn*20];
	ll qpow(int a,int b)
	{
		if(!b)return 1;
		ll c=qpow(a,b/2);
		c=1ll*c*c%p;
		if(b&1)c=c*a%p;
		return c;
	}
	void work(){
		jc[0]=1;
		for(int i=1;i<maxn*20;i++)
			jc[i]=(jc[i-1]*i)%p;
		for(int i=0;i<maxn*20;i++)
			inv[i]=qpow(jc[i],p-2);
		n++;
		for(int i=0;i<=n;i++)
			f[i][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
				for(int len=1;len<=i;len++)
					for(int l=1;l+len-1<=i;l++)
						for(int u=0;u<j;u++)
							for(int v=0;u+v<j;v++)
								f[i][j]=(f[i][j]+f[l-1][u]*f[len-1][j-u-v-1]%p*f[i+1-l-len][v]%p*jc[j-1]%p*inv[u]%p*inv[j-u-v-1]%p*inv[v])%p;
		printf("%lld",f[n][k]);
	}
}
namespace subtask3{
	int a[]={1,663613190,598048000,281056452,229675900,351468303,165767177,513317092,847523741,9129324};
	void work()
	{
		if(n<499122177){
			ans=a[n/50000000];
			for(int i=n/50000000*50000000+1;i<=n;i++){
				ans=(1ll*ans*(2*i+1))%p;
			} 
		}
		printf("%d",ans);
	}
}
int main(){
	freopen("reverse.in","r",stdin);
	freopen("reverse.out","w",stdout);
	scanf("%d%lld%lld",&type,&n,&k);
	if(type==1)subtask1::work();
	else if(type==2&&k<n+1)subtask2::work();
	else subtask3::work();
}
