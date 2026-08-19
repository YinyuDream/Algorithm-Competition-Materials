#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=19;
int n,W;
int a[maxn],pos[1<<maxn],w[1<<maxn],f[1<<maxn];
int main(){
	scanf("%d%d",&n,&W);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=0;i<=n;i++)
	pos[1<<i]=i+1;
	for(int i=1;i<(1<<n);i++)
		for(int j=i;j;j-=j&-j)
			w[i]+=a[pos[j&-j]];
	for(int i=1;i<(1<<n);i++)
	{
		if(w[i]<=W){
			f[i]=1;continue;
		}
		for(int j=i;j;j=(j-1)&i)
		{
			f[i]=min(f[i],f[i-j]+f[j]);
		}
	}
	printf("%d",f[(1<<n)-1]);
	return 0;
}
