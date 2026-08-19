#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long lxl;
const int maxn=105;

template <typename T>
inline void read(T &x)
{
	x=0;T f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	x*=f;
}

struct BigNumber
{
	short D[maxn];
	int len;
	BigNumber(int x)
	{
		memset(D,0,sizeof(D));len=0;
		while(x) D[++len]=x%10,x/=10;
		len=max(len,1);
	}
	BigNumber(){}
	inline BigNumber operator + (const BigNumber &T)const
	{
		BigNumber res=BigNumber(0);
		int las=0;
		for(int i=1,L=max(len,T.len);i<=L;++i)
		{
			res.D[i]=D[i]+T.D[i]+las;
			las=res.D[i]/10;
			res.D[i]%=10;
		}
		res.len=max(len,T.len);
		if(las) res.D[++res.len]=las;
		return res;
	}
	inline BigNumber operator + (const int &T)const
	{
		BigNumber res=BigNumber(0);
		short las=0;
		for(int i=1;i<=len;++i)
		{
			res.D[i]=D[i]+(i==1?T:0)+las;
			las=res.D[i]/10;
			res.D[i]%=10;
		}
		res.len=len;
		if(las) res.D[++res.len]=las;
		return res;
	}
	inline BigNumber operator - (const BigNumber &T)const
	{
		BigNumber res=BigNumber(0);
		bool las=false;
		for(int i=1;i<=len;++i)
		{
			res.D[i]=D[i]-las-T.D[i];
			las=res.D[i]<0;
			res.D[i]+=las*10;
		}
		res.len=len;
		while(!res.D[res.len]) --res.len;
		res.len=max(res.len,1);
		return res;
	}
	inline void print()
	{
		int p=len;
		while(p) putchar(D[p--]+'0');
	}
}M[maxn][maxn],sum1[maxn][maxn],sum2[maxn][maxn];

int n;

int main()
{
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	read(n);
	BigNumber now=BigNumber(0);
	now=now+1;
	for(int i=1;i<=n;++i)
	{
		M[1][i]=sum1[1][i]=sum2[1][i]=BigNumber(0);
		M[i][n]=sum1[i][n]=sum2[i][n]=BigNumber(0);
	}
	for(int i=2;i<=n;++i)
		for(int j=n-1;j>=1;--j)
		{
			M[i][j]=now-sum1[i][j+1]-sum2[i-1][j];
			sum1[i][j]=sum1[i][j+1]+M[i][j];
			sum2[i][j]=sum2[i-1][j]+M[i][j];
			now=sum1[i][j]+sum1[i-1][1];
			now=now-sum1[i-1][j+1]+1;
			if(i>2) now=now+sum2[i-2][1];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			M[i][j].print(),putchar(j==n?'\n':' ');
	return 0;
}
