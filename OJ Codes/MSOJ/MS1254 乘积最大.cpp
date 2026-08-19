#include<cstdio>
using namespace std;
const int maxn=42;
int n,m;
char t[maxn];
struct Bignum{
	int len=0;
	int num[4010]={0};
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
	void pt(){
		for(int i=len;i>=1;i--)
		printf("%d",num[i]);
	}
	friend Bignum operator*(Bignum x,Bignum y)
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
		while(c.num[top]==0)top--;
		c.len=top;
		return c;
	}
	friend Bignum operator*(Bignum x,int y)
	{
		Bignum c;
		c.build(y);
		return x*c;
	}
	friend Bignum operator+(Bignum x,Bignum y)
	{
		Bignum c;
		int add=0;
		for(int i=1;i<=n+1;i++){
			c.num[i]=(x.num[i]+y.num[i]+add);
			add/=10;
			c.num[i]%=10;
		}
		int k=x.len>y.len?x.len:y.len+1;
		while(c.num[k]!=0)k--;
		c.len=k;
		return c;
	}
};
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
int a[maxn];
Bignum num[maxn][maxn];//i到往前j长度的数字值
Bignum dp[maxn][maxn];
Bignum pow(Bignum x,int p)
{
	if(p==0){
		Bignum w;
		w.build(1);
		return w;
	}
	if(p==1)return x;
	Bignum q=pow(x,p/2);
	if(p%2==0)return q*q;
	else return q*q*x;
}
int main(){
	scanf("%d%d %s",&n,&m,t+1);
	for(int i=1;i<=n;i++)
		a[i]=t[i]-'0',num[i][1].build(a[i]);
	for(int len=2;len<=n;len++){
		for(int i=n;i-len+1>=1;i--){
			Bignum y;
			y.build(10);
			num[i][len]=num[i][len-1]+pow(y,len-1)*a[i-len+1];
		}
	}
	for(int i=1;i<=n;i++)
		dp[i][0]=num[i][i];
	for(int i=2;i<=n;i++){//前i个数 
		for(int j=1;j<=m;j++){//j个*号 
			for(int k=1;k<i;k++){//断点
				dp[i][j]=max(dp[k][j-1]*num[i][i-k],dp[i][j]); 
			}
		}
	}
	dp[n][m].pt();
	return 0;
}