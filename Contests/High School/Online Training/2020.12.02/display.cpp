#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1e4+10,maxk=32;
const ll p=1e9+7;
int n,x;
ll d,m;
int book[maxk],a[10]={10,8,18,28,9,21,6,24,23,29};
namespace subtask1{
	struct matrix{
		ll num[maxk][maxk];
		matrix(){
			memset(num,0,sizeof num);
		}
	}st,A,B,C,ans;
	matrix operator*(const matrix &a,const matrix &b)
	{
		matrix c;
		for(int i=0;i<maxk;i++)
			for(int j=0;j<maxk;j++)
				for(int k=0;k<maxk;k++)
					(c.num[i][j]+=a.num[i][k]*b.num[k][j])%=p;
		return c;
	}
	matrix qpow(const matrix &a,ll b)
	{
		matrix c;
		if(!b){
			for(int i=0;i<maxk;i++)
				c.num[i][i]=1;
			return c;
		}
		c=qpow(a,b/2);
		c=c*c;
		if(b&1)c=c*a;
		return c;
	}
	bool check(int x)
	{
		return x==(x&(-x));
	}
	void work(){
		st.num[0][a[x]]=1;
		for(int i=0;i<maxk;i++)
			for(int j=0;j<=4;j++)
				A.num[i^(1<<j)][i]=1;
		for(int i=0;i<=9;i++)
			for(int j=0;j<=4;j++)
				B.num[a[i]^(1<<j)][a[i]]=1;
		C=qpow(A,d-1)*B;
		ans=st*qpow(C,m/d)*qpow(A,m%d);
		for(int i=0;i<=9;i++)
			printf("%lld\n",ans.num[0][a[i]]);
	}
}
namespace subtask2{
	ll f[maxn][maxk][maxk];
	void work(){
		f[0][a[x/10]][a[x%10]]=1;
		for(int i=1;i<=m;i++)
			for(int j=0;j<=31;j++)
				for(int k=0;k<=31;k++)
					if(i%d!=0||(i%d==0&&book[j]&&book[k]))
						for(int l=0;l<=4;l++)
							(f[i][j][k]+=f[i-1][j^(1<<l)][k]+f[i-1][j][k^(1<<l)])%=p;
		for(int i=0;i<=9;i++)
			for(int j=0;j<=9;j++)
				printf("%lld\n",f[m][a[i]][a[j]]);
	}
}
int main(){
	freopen("display.in","r",stdin);
	freopen("display.out","w",stdout);
	scanf("%d%lld%lld%d",&n,&m,&d,&x);//n个屏幕，操作m次，每d次，第一个数为x 
	for(int i=0;i<=9;i++)
		book[a[i]]=1;
	if(n==1)subtask1::work();
	else subtask2::work();	
	return 0;
}
