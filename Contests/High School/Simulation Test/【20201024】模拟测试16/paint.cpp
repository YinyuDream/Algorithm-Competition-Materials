#include<cstdio>
using namespace std;
const int maxn=1e2+10;
int n,c,q;
double p[maxn][maxn][maxn];
double ans;
int read()
{
	int x=0,sign=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')sign=-sign;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=x*10+ch-48,ch=getchar();
	return x*sign;
}
int work(int s,int l,int r)
{
	for(int i=1;i<l;i++)
		for(int j=0;j<c;j++)
			p[s+1][i][j]=p[s][i][j];
	for(int i=r+1;i<=n;i++)
		for(int j=0;j<c;j++)
			p[s+1][i][j]=p[s][i][j];
	for(int i=l;i<=r;i++){
		for(int j=0;j<c;j++){
			p[s+1][i][j]+=p[s][i][j]/2;
			for(int k=0;k<c;k++){
				p[s+1][i][j*k%c]+=p[s][i][j]*0.5/c;
			}
		}
	}
} 
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	n=read(),c=read(),q=read();
	for(int i=1;i<=n;i++)
		p[0][i][1]=1;
	for(int i=1,l,r;i<=q;i++){
		l=read(),r=read();
		work(i-1,l,r);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<c;j++){
			ans+=p[q][i][j]*j;
		}
	}
	printf("%.3f",ans);
	return 0;
}
