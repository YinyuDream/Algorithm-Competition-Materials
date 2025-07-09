#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int n,m,ans,book[maxn][maxn];
double r;
int main(){
	scanf("%d%d%lf",&n,&m,&r);
	for(int i=1;i<=m;i++){
		double x,y;
		scanf("%lf%lf",&x,&y);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if((i-x)*(i-x)+(j-y)*(j-y)<=r*r)
					book[i][j]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(book[i][j])
				ans++;
	printf("%d",ans);
	return 0;
}