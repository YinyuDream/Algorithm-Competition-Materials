#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=500005;
int n;
char str[maxn];
double f[maxn],d[maxn];
int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='o') {d[i]=d[i-1]+1.0;f[i]=f[i-1]+(2.0*d[i]-1.0);}
		else if(str[i]=='x') {d[i]=0;f[i]=f[i-1];}
		else{f[i]=f[i-1]+d[i-1]+0.5;d[i]=(d[i-1]+1.0)/2.0;}
	}
	printf("%.4lf\n",f[n]);
	return 0;
}
