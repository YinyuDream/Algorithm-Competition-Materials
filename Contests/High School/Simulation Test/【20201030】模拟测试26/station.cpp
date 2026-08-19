#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=110;
int x[maxn],y[maxn],dfn[maxn],cnt,ans=0x7f7f7f7f;
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	for(int i=1;i<=8;i++){
		char s[maxn];
		scanf("%s",s+1);
		for(int j=1;j<=8;j++)
			if(s[j]=='#')
				x[++cnt]=i,y[cnt]=j;
	}
	for(int i=1;i<=cnt;i++)
		dfn[i]=i;
	do{
		int num=0;
		for(int i=2,mx;i<=cnt;i++){
			mx=0;
			for(int j=1;j<i;j++)
				mx=max(mx,max(abs(x[dfn[i]]-x[dfn[j]]),abs(y[dfn[i]]-y[dfn[j]])));
			num+=mx;
		}
		ans=min(ans,num);
	}
	while(next_permutation(dfn+1,dfn+cnt+1));
	printf("%d",ans);
	return 0;
}
