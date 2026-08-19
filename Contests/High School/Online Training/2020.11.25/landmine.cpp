#include<bits/stdc++.h>
using namespace std;
const int maxn=75;
int n,ans,p[maxn],q[maxn],r[maxn],s[maxn],a[maxn],pre[maxn],net[maxn];
int check()
{
	int num=0;
	for(int i=1;i<=n;i++){
		num+=(p[pre[a[i]]]-q[a[i]])*(p[pre[a[i]]]-q[a[i]]);
		num+=(p[a[i]]-r[net[a[i]]])*(p[a[i]]-r[net[a[i]]]);
		num+=(p[net[a[i]]]-s[net[net[a[i]]]])*(p[net[a[i]]]-s[net[net[a[i]]]]);
		net[a[i]]=net[net[a[i]]];
		pre[a[i]]=pre[pre[a[i]]];
		pre[net[a[i]]]=a[i];
		net[pre[a[i]]]=a[i];
	}
	return num;
}
int main(){
	freopen("landmine.in","r",stdin);
	freopen("landmine.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&q[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
		a[i]=i;
	do{
		for(int i=1;i<=n;i++){
			pre[i]=i-1;
			net[i]=i+1;
		}
		ans=max(ans,check());
	}while(next_permutation(a+1,a+n+1));
	printf("%d\n",ans);
	return 0;
}
