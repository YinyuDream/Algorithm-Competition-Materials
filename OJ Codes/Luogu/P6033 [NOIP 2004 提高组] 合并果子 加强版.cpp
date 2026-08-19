#include<cstdio>
using namespace std;
const int maxm=1e5+10,maxn=1e7+10;
int n,la=1,lb=1,rb,cnt;
int book[maxm];
long long a[maxn],b[maxn],ans;
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	ch=getchar();
	while(ch<='9'&&ch>='0')
	x=x*10+ch-48,
	ch=getchar();
	return x;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		book[a[i]]++;
	for(int i=1;i<maxm;i++)
		while(book[i])
			a[++cnt]=i,book[i]--;
	for(int i=1;i<n;i++)
	{
		long long t=0x7f7f7f7f7f7f7f7fll;
		int opt;
		if(la<=n&&lb<=rb&&a[la]+b[lb]<t)opt=1,t=a[la]+b[lb];
		if(la+1<=n&&a[la]+a[la+1]<t)opt=2,t=a[la]+a[la+1];
		if(lb+1<=rb&&b[lb]+b[lb+1]<t)opt=3;
		if(opt==1){
			ans+=a[la]+b[lb];
			la++;lb++;
			b[++rb]=a[la]+b[lb];
		}else if(opt==2){
			ans+=a[la]+a[la+1];
			b[++rb]=a[la]+a[la+1];
			la+=2;
		}else if(opt==3){
			ans+=b[lb]+b[lb+1];
			b[++rb]=b[lb]+b[lb+1];
			lb+=2;
		}
	}
	printf("%lld",ans);
	return 0;
}