#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=100;
int n,m;
struct Bignum{
	int len=0;
	int num[105]={0};
	void build(int x)
	{
		int top=0,t[20]={0}; 
		while(x){
			t[++top]=x%10;
			x/=10;
		}
		for(int i=1;i<=top;i++){
			num[i]=t[i];
		}
		len=top;
	}
	void rev()
	{
		for(int i=1;i<=len/2;i++){
			swap(num[i],num[len-i+1]);
		}
	}
	void pt(){
		if(!len){
			puts("0");
			return ; 
		}
		for(int i=len;i>=1;i--)
		printf("%d",num[i]);
	}
};
Bignum operator+(Bignum x,Bignum y)
{
	int len=max(x.len,y.len);
	Bignum c;
	for(int i=1;i<=len;i++)
	{
		c.num[i]+=x.num[i]+y.num[i];
		c.num[i+1]+=c.num[i]/10;
		c.num[i]%=10;
	}
	if(c.num[len+1]!=0)len++;
	while(c.num[len]==0&&len)len--;
	c.len=len;
	return c;
}
Bignum operator*(Bignum x,Bignum y)
{
	Bignum c;
	for(int i=1;i<=x.len;i++){
		for(int j=1;j<=y.len;j++){
			c.num[i+j-1]+=x.num[i]*y.num[j];
			c.num[i+j]+=c.num[i+j-1]/10;
			c.num[i+j-1]%=10;
		}
	}
	int top=x.len+y.len;
	while(c.num[top]==0&&top)top--;
	c.len=top;
	return c;
}
Bignum max(Bignum x,Bignum y)
{
	if(x.len!=y.len){
		return x.len>y.len?x:y;
	}
	else{
		for(int i=x.len;i>=1;i--){
			if(x.num[i]>y.num[i])return x;
			else if(x.num[i]<y.num[i])return y;
		}
		return x;
	}
}
Bignum Fast_pow(Bignum a,int b)
{
	if(b==0){
		Bignum q;
		q.build(1);
		return q;
	}
	if(b==1)return a;
	Bignum c=Fast_pow(a,b/2)*Fast_pow(a,b/2);
	if(b&1)return c*a;
	else return c;
}
Bignum ans,a[maxn][maxn],dp[maxn][maxn];
int main(){
	Bignum two;
	two.build(2);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int v;
			scanf("%d",&v);
			a[i][j].build(v);
		}
	for(int i=1;i<=n;i++)
	{
		Bignum cnt;
		for(int j=m-1;j>=1;j--)
		{
			Bignum d=Fast_pow(two,m-j);
			for(int k=1;k<=m-j+1;k++)
				dp[k][k+j-1]=max(dp[k-1][k+j-1]+d*a[i][k-1],dp[k][k+j]+d*a[i][k+j]);
		}
		Bignum d=Fast_pow(two,m);
		for(int j=1;j<=m;j++)
			cnt=max(cnt,dp[j][j]+d*a[i][j]);
		ans=cnt+ans;
	}
	ans.pt();
	return 0;
}
