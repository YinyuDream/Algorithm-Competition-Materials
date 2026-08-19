#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m;
int x[maxn],y[maxn];
namespace subtask1{
	bool f[5000005][32];
	char g[5000005][32];
	void work(){
		f[0][(1<<n)-1]=1;
		for(int i=0;i<m;i++){
			for(int j=0;j<(i<<n);j++){
				
			}
		}
	}
}
namespace subtask2{
	int num[maxn],a[maxn];
	bool check()
	{
		for(int i=1;i<=n;i++)
			a[i]=1;
		for(int i=1;i<=m;i++){
			if(num[i]==0&&a[y[i]]==1){
				a[y[i]]=0;
				a[x[i]]=1;
			}else if(num[i]==1&&a[x[i]]==1){
				a[x[i]]=0;
				a[y[i]]=1;
			}
		}
		int num=0;
		for(int i=1;i<=n;i++)
			num+=a[i];
		return num>=n/2;
	}
	void dfs(int pos)
	{
		if(pos==m+1){
			if(check()){
				puts("YES");
				for(int i=1;i<=m;i++)
					printf("%d",num[i]);
				exit(0);
			}
			return ;
		}
		num[pos]=0;
		dfs(pos+1);
		num[pos]=1;
		dfs(pos+1);
	}
}
int main(){
	printf("%d\n",sizeof (bool));
	//freopen("network.in","r",stdin);
	//freopen("network.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x[i],&y[i]);
	if(n<=5)subtask1::work();
	else subtask2::dfs(1),puts("NO");
	return 0;
}
