#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+10;
int n,pos,t;
int st[maxn],tp;
int a[maxn],ans[maxn],pre[maxn],mapp[maxn][maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,t;i<n;i++)
		for(int j=i+1;j<=n;j++)
			scanf("%d",&t),
			mapp[i][j]=mapp[j][i]=t;
	for(int i=1;i<=n;i++)
		ans[i]=a[i],pre[i]=i;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			if(mapp[i][j]&&ans[i]<ans[j]+a[i])
				ans[i]=ans[j]+a[i],
				pre[i]=j;
	for(int i=1;i<=n;i++)
		if(ans[pos]<ans[i])
			t=pos=i;
	while(pre[t]!=t)
		st[++tp]=t,
		t=pre[t];
	st[++tp]=t;
	for(int i=tp;i;i--)
		printf("%d ",st[i]);
	puts("");
	printf("%d",ans[pos]);
	return 0;
}