#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int n;
double x[maxn],y[maxn],mx=1e16;
double dis(int p,int q)
{
	return sqrt((x[p]-x[q])*(x[p]-x[q])+(y[p]-y[q])*(y[p]-y[q]));
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			mx=min(mx,dis(i,j));
	printf("%.4f",mx);
	return 0;
}