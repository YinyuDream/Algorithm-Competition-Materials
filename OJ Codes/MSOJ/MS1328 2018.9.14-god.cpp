#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int T,n;
int a[maxn];
int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
	return x;
}
int main(){
	//freopen("god.in","r",stdin);
	//freopen("god.out","w",stdout);
		n=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		nth_element(a+1,a+n/2+1,a+n+1);
		printf("%d\n",a[n/2+1]);
}