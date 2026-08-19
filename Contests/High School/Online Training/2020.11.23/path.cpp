#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn=1e2+10;
int n;
struct Bignum{
	int len,num[510];
	Bignum(){
		len=0;
		memset(num,0,sizeof num);
	}
	Bignum(int x){
		len=0;
		memset(num,0,sizeof num); 
		while(x){
			num[++len]=x%10;
			x/=10;
		}
	}
	void rev()
	{
		for(int i=1;i<=len/2;i++)
			swap(num[i],num[len-i+1]);
	}
	void print(){
		if(!len)printf("0");
		for(int i=len;i>=1;i--)
		printf("%d",num[i]);
	}
	Bignum operator=(int y)
	{
		len=0;
		memset(num,0,sizeof num); 
		while(y){
			num[++len]=y%10;
			y/=10;
		}
		return *this;
	}
	Bignum operator+(const Bignum &y)
	{
		Bignum c;
		c.len=max(len,y.len);
		for(int i=1;i<=c.len;i++){
			c.num[i]+=num[i]+y.num[i];
			c.num[i+1]+=c.num[i]/10;
			c.num[i]%=10;
		}
		if(c.num[c.len+1])c.len++;
		while(c.len&&!c.num[c.len])c.len--;
		return c;
	}
	Bignum operator-(const Bignum &y)
	{
		Bignum c;
		c.len=max(len,y.len);
		for(int i=1;i<=c.len;i++){
			c.num[i]=num[i]-y.num[i];
			if(c.num[i]<0){
				c.num[i]+=10;
				num[i+1]--;
			}
		}
		while(c.len&&!c.num[c.len])c.len--;
		return c;
	}
	Bignum operator*(const Bignum &y)
	{
		Bignum c;
		for(int i=1;i<=len;i++){
			for(int j=1;j<=y.len;j++){
				c.num[i+j-1]+=num[i]*y.num[j];
				c.num[i+j]+=c.num[i+j-1]/10;
				c.num[i+j-1]%=10;
			}
		}
		c.len=len+y.len;
		while(c.len&&!c.num[c.len])c.len--;
		return c;
	}
}f[maxn][maxn],g[maxn][maxn];
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		for(int j=n;j>=1;j--){
			Bignum sumr(0),sumu(0);
			if(j<n){
				for(int l=j+1;l<=n;l++)sumr=sumr+f[i][l];
				for(int l=i-1;l>=1;l--)sumu=sumu+f[l][j];
				f[i][j]=g[i][j+1]+1-sumr-sumu;
			}
			sumu=0;
			for(int l=j;l>=1;l--)sumu=sumu+f[i-1][l];
			for(int l=i-2;l>=1;l--)sumu=sumu+f[l][1];
			g[i][j]=sumr+sumu+f[i][j];
		}
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			f[i][j].print(),putchar(' ');
	return 0;
}
