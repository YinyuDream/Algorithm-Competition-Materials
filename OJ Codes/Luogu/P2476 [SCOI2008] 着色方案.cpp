#include<cstdio>
using namespace std;
const int maxn=20;
int n,k,cnt;
int c[maxn];
void dfs(int pre,int step)
{
	if(step==n){
		cnt++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(i!=pre&&c[i]>0){
			c[i]--;
			dfs(i,step+1);
			c[i]++; 
		}
	}
}
int main(){
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&c[i]),n+=c[i];
	dfs(0,0);
	printf("%d",cnt); 
	return 0;
} 