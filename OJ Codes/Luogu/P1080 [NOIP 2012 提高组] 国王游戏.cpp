#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+10;
int n;
void swap(int &a,int &b)
{
	int c=b;b=a;a=c;
}
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
	void rev()
	{
		for(int i=1;i<=len/2;i++){
			swap(num[i],num[len-i+1]);
		}
	}
	void pt(){
		for(int i=len;i>=1;i--)
		printf("%d",num[i]);
	}
};
Bignum mul,ans;
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
	while(c.num[top]==0)top--;
	c.len=top;
	return c;
}
Bignum operator*(Bignum x,int y)
{
	Bignum c;
	c.build(y);
	return x*c;
}
Bignum operator/(Bignum x,int y)
{
	Bignum c;
	x.rev();
	for(int i=1;i<=x.len;i++){
		c.num[i]=(x.num[i])/y;
		x.num[i+1]+=(x.num[i]%y)*10; 
	}
	c.len=x.len,c.rev();
	while(c.num[c.len]==0)c.len--;
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
struct node{
	int l,r;
}a[maxn];
bool cmp(node a,node b){
	return a.l*a.r<b.l*b.r;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		scanf("%d%d",&a[i].l,&a[i].r); 
	}
	sort(a+1,a+n+1,cmp);
	mul.build(a[0].l);
	for(int i=1;i<=n;i++){
		ans=max(ans,mul/a[i].r);
		mul=mul*a[i].l;
	}
	ans.pt();
	return 0;
} 