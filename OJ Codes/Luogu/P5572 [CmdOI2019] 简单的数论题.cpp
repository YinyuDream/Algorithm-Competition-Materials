#include<cstdio>
using namespace std;
const int mod=23333;
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int getans(int a,int b)
{
	int ans=0,cnt=0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cnt=0;
			int t=gcd(i,j),temp=i*j/t;
			t=temp/t;
			for(int i=1;i<=t;i++)
			{
				if(gcd(i,t)==1)cnt++; 
			} 
			ans=(cnt%mod+ans%mod)%mod;
		}
	}
	return ans%mod;
}
int main(){
	int m,n,t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&n,&m);
		{
			printf("%d\n",getans(n,m));
		}
	 } 
}
