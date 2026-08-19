#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+10;
int n;
struct Bignum{
	int len=0;
	int num[maxn]={0};
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
}ans;
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
Bignum operator*(int x,Bignum y)
{
	Bignum c;
	c.build(x);
	return c*y;
}
Bignum operator/(Bignum x,int y)
{
	Bignum c;
	c.rev();
	int t=0;
	for(int i=1;i<=x.len;i++){
		c.num[i]=(x.num[i]+t*10)/y;
		t=(t*10+x.num[i])%y;	
	}
	c.len=1;
	while(c.num[c.len]==0&&c.len<=x.len)c.len++;
	for(int i=c.len;i<=x.len;i++)
		c.num[i-c.len+1]=c.num[i];
	c.len=x.len-c.len+1;
	return c;
}
int main(){
	scanf("%d",&n);
	ans.build(1);
	for(int i=1;i<=n*2;i++)
		ans=i*ans;
	for(int i=1;i<=n;i++)
		ans=ans/i;
	for(int i=1;i<=n+1;i++)
		ans=ans/i;
	ans.pt();
	return 0;
}
