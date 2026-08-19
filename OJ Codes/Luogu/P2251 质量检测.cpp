#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m;
int a[maxn];
int st[maxn][21];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		st[i][0]=a[i];
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=n-m+1;i++){
		int p=log(m)/log(2);
		printf("%d\n",min(st[i][p],st[m+i-(1<<p)][p])); 
	}
	return 0;
} 