#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int a[maxn];
int n;
int dfs(int x)
{
	int ans=1;
	for(int i=1;i<=x/2;i++){
		if(a[i]!=0)ans+=a[i];
		else ans+=dfs(i);
	}
	return a[x]=ans;
}
int main(){
	scanf("%d",&n),dfs(n),printf("%d",a[n]);
	return 0;
}
