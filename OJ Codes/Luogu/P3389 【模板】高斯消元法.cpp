#include<cstdio>
using namespace std;
const int maxn=120;
int n;
double a[maxn][maxn];
double abs(double a){
	return a<0?a:-a;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			scanf("%lf",&a[i][j]);
	for(int i=1;i<=n;i++)//x1---xn
	{
		for(int j=i+1;j<=n;j++)
		{
			double m=-(a[i][i]/a[j][i]);
			for(int k=1;k<=n+1;k++)
			a[j][k]*=m,a[j][k]+=a[i][k];
		}
	}
	for(int i=1;i<=n;i++)
	{
		int book=0;
		for(int j=i;j<=n;j++)
		{
			if(abs(a[i][j]-0)<=1e-4)book++;
		}
		if(book!=0&&a[i][n+1]==0){
			puts("No Solution");
			return 0;
		}
	}
	for(int i=n;i>=1;i--)
	{
		double m=a[i][n+1];
		for(int j=n;j>i;j--)m-=a[i][j];
		a[i][n+1]=m/a[i][i];
		a[i][i]=1;
		for(int j=i-1;j>=1;j--)a[j][i]=a[i][n+1]*a[j][i];
		for(int j=1;j<=n;j++)
			if(i!=j)a[i][j]=0;
	}
	for(int i=1;i<=n;i++)
		printf("%.2f\n",a[i][n+1]);
	return 0;
}