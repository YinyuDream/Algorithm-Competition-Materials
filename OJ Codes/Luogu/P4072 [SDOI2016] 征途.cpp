#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3e3+10;
int n,m;
int a[maxn],sum[maxn],f[maxn][maxn];//Ç°i¶Î·Ö³Éj
int q[maxn],front,back;
inline int Y(int x,int k){return f[x][k]+sum[x]*sum[x];}
inline int X(int x){return sum[x];}
inline double slope(int x,int y,int k){return X(x)==X(y)?(Y(y,k)>=Y(x,k)?2e9:-2e9):(1.0*Y(y,k)-Y(x,k))/(1.0*X(y)-X(x));}
int main(){
	memset(f,0x3f,sizeof f);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		f[i][1]=sum[i]*sum[i];
	for(int j=2;j<=m;j++){
		front=1,back=0;
		q[++back]=j-1;
		for(int i=j;i<=n;i++){
			while(front<back&&slope(q[front],q[front+1],j-1)<=2*sum[i])front++;
			f[i][j]=f[q[front]][j-1]+(sum[i]-sum[q[front]])*(sum[i]-sum[q[front]]);
			while(front<back&&slope(q[back-1],q[back],j-1)>=slope(q[back-1],i,j-1))back--;
			q[++back]=i;
		}
	}
	printf("%d",m*f[n][m]-sum[n]*sum[n]);
	return 0;
}
