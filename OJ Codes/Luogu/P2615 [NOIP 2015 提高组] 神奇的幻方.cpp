#include<cstdio>
using namespace std;
const int maxn=1e3+10;
int n;
int a[maxn][maxn],posx[maxn],posy[maxn];//行列标记 
int main(){
	scanf("%d",&n);
	a[1][(n+1)/2]=1;
	posx[1]=1;
	posy[1]=(n+1)/2;
	for(int k=2;k<=n*n;k++)
	{
		if(posx[k-1]==1&&posy[k-1]!=n){
			a[n][posy[k-1]+1]=k;
			posx[k]=n;
			posy[k]=posy[k-1]+1;
		}else if(posx[k-1]!=1&&posy[k-1]==n){
			a[posx[k-1]-1][1]=k;
			posx[k]=posx[k-1]-1;
			posy[k]=1;
		}else if(posx[k-1]==1&&posy[k-1]==n){
			a[posx[k-1]+1][n]=k;
			posx[k]=posx[k-1]+1;
			posy[k]=n;
		}else{
			if(!a[posx[k-1]-1][posy[k-1]+1])
			{
				a[posx[k-1]-1][posy[k-1]+1]=k;
				posx[k]=posx[k-1]-1;
				posy[k]=posy[k-1]+1;
			}
			else
			{
				a[posx[k-1]+1][posy[k-1]]=k;
				posx[k]=posx[k-1]+1;
				posy[k]=posy[k-1];
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			printf("%d%c",a[i][j],j==n?'\n':' ');
	return 0;
}
