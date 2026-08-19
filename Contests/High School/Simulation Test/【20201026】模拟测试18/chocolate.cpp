#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=11,maxk=16;
int T,n,m,k;
int w[maxn][maxn],sum[maxn][maxn],q[maxn],bit_cnt[1<<maxk],bit_sum[1<<maxk];
char book[maxn][maxn][maxn][maxn][1<<(maxk-1)];
bool dfs(int a,int b,int c,int d,int status)
{
	if(bit_sum[status]!=sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1])
	return book[a][b][c][d][status]=0;
	if(status==(status&(-status)))
	return book[a][b][c][d][status]=(sum[c][d]-sum[a-1][d]-sum[c][b-1]+sum[a-1][b-1]==q[bit_cnt[status]+1]);
	if(book[a][b][c][d][status]!=-1)
	return book[a][b][c][d][status];
	int res=0;
	for(int i=a;i<c;i++){
		for(int j=(status-1)&status;j;j=(j-1)&status){
			res|=(dfs(a,b,i,d,j)&dfs(i+1,b,c,d,j^status));
		}
	}
	for(int i=b;i<d;i++){
		for(int j=(status-1)&status;j;j=(j-1)&status){
			res|=(dfs(a,b,c,i,j)&dfs(a,i+1,c,d,j^status));
		}
	}
	return book[a][b][c][d][status]=res;
}
int main(){
	freopen("chocolate.in","r",stdin);
	freopen("chocolate.out","w",stdout);
	for(int i=1;i<=maxk;i++)
		bit_cnt[1<<(i-1)]=i-1;
	scanf("%d",&T);
	while(T--){
		memset(bit_sum,0,sizeof bit_sum);
		memset(book,-1,sizeof book);
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&w[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum[i][j]=sum[i-1][j]+sum[i][j-1]+w[i][j]-sum[i-1][j-1];
		for(int i=1;i<=k;i++){
			scanf("%d",&q[i]);
			for(int j=0;j<(1<<k);j++){
				if(j&(1<<(i-1))){
					bit_sum[j]+=q[i];
				}
			}
		}
		printf("%s\n",dfs(1,1,n,m,(1<<k)-1)?"yes":"no");
	}
	return 0;
}
