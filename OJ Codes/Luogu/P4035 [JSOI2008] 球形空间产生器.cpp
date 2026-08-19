#include<cstdio>
using namespace std;
const int N=12;
double a[N][N],gauss[N][N];
int n;
void Gauss()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double m=-(gauss[i][i]/gauss[j][i]);
			for(int k=1;k<=n+1;k++)
			gauss[j][k]*=m,gauss[j][k]+=gauss[i][k];
		}
	}
	for(int i=n;i>=1;i--)
	{
		double m=gauss[i][n+1];
		for(int j=n;j>i;j--)m-=gauss[i][j];
		gauss[i][n+1]=m/gauss[i][i];
		gauss[i][i]=1;
		for(int j=i-1;j>=1;j--)gauss[j][i]=gauss[i][n+1]*gauss[j][i];
		for(int j=1;j<=n;j++)
			if(i!=j)gauss[i][j]=0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++)
		for(int j=1;j<=n;j++)
			scanf("%lf",&a[i][j]);
	for(int i=1;i<=n;i++){
		double sum=0;
		for(int j=1;j<=n;j++){
			gauss[i][j]=(a[i][j]-a[i+1][j]);
			sum+=(a[i][j]*a[i][j]-a[i+1][j]*a[i+1][j]);
		}
		gauss[i][n+1]=sum/2;
	}
	Gauss();
	for(int i=1;i<=n;i++)
		printf("%.3f ",gauss[i][n+1]);
	return 0;
} 
