#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e3+10;
int n,maxp,w;
int ap[maxn],bp[maxn],as[maxn],bs[maxn];
int f[maxn][maxn];
int q[maxn],head,tail;
int main(){
	memset(f,-0x3f,sizeof f);
	f[0][0]=0;
	scanf("%d%d%d",&n,&maxp,&w);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
	for(int i=1;i<=n;i++){
		head=1,tail=0;
		for(int j=0;j<=maxp;j++)
			f[i][j]=max(f[i][j],f[i-1][j]);
		for(int j=1;j<=maxp;j++){
			if(head<=tail&&q[head]<j-min(j,as[i]))head++;
			while(head<=tail&&f[max(i-w-1,0)][q[tail]]-(j-q[tail])*ap[i]<=f[max(i-w-1,0)][j-1]-ap[i])tail--;
			q[++tail]=j-1;
			f[i][j]=max(f[i][j],f[max(i-w-1,0)][q[head]]-(j-q[head])*ap[i]);
		}
		head=1,tail=0;
		for(int j=maxp-1;j>=0;j--){
			if(head<=tail&&q[head]>j+min(bs[i],maxp-j))head++;
			while(head<=tail&&f[max(i-w-1,0)][q[tail]]+(q[tail]-j)*bp[i]<=f[max(i-w-1,0)][j+1]+bp[i])tail--;
			q[++tail]=j+1;
			f[i][j]=max(f[i][j],f[max(i-w-1,0)][q[head]]+(q[head]-j)*bp[i]);
		}
	}
	printf("%d",f[n][0]);
	return 0;
}
