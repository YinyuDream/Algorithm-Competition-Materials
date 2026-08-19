#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
char str[maxn];
long long tot[10],c[maxn][maxn],ans=0;
int len;
void getpre()
{
	c[0][0]=1;
	for(int i=1;i<=50;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=50;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
}
long long get(long long n)
{
	long long ans=1;
	for(int i=0;i<=9;i++) ans*=c[n][tot[i]],n-=tot[i];
	return ans;
}
int main()
{
	getpre();
	scanf("%s",str+1);
	len=strlen(str+1);
	for(int i=1;i<=len;i++) tot[str[i]-48]++;
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<str[i]-48;j++) tot[j]--,ans+=get(len-i),tot[j]++;//当前选了0~x-1中的数，那么后面每一位都可以随便选
		tot[str[i]-48]--;
	}
	printf("%lld",ans);
	return 0;
}
