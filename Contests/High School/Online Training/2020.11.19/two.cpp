#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,m,ans;
priority_queue<int,vector<int>,greater<int> >q[maxn];
int main(){
	freopen("two.in","r",stdin);
	freopen("two.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=n;i++)
		scanf("%d%d",&u,&v),q[u].push(v);
	ans=n;
	for(int i=1,opt,u,v;i<=m;i++){
		scanf("%d%d%d",&opt,&u,&v);
		if(opt==1)
			q[u].push(v),ans++;
		else
			for(int k=sqrt(v),j=max(1,u-k);j<min(u+k+1,maxn);j++)
				while(q[j].size()&&1ll*(u-j)*(u-j)+q[j].top()<=1ll*v)
					q[j].pop(),ans--;
		printf("%d\n",ans);
	}
	return 0;
}
