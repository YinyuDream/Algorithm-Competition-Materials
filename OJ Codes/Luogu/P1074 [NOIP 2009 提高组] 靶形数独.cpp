#include<cstdio>
#include<algorithm>
using namespace std;
const int n=9;
int mapp[n+1][n+1],sum;
struct node{
	int cnt,id;
}m[12];
int f[n+1][n+1]={
	{0,0,0,0,0,0,0,0,0,0},
	{0,6,6,6,6,6,6,6,6,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,9,10,9,8,7,6},
	{0,6,7,8,9,9,9,8,7,6},
	{0,6,7,8,8,8,8,8,7,6},
	{0,6,7,7,7,7,7,7,7,6},
	{0,6,6,6,6,6,6,6,6,6},
};
int a[n+1][n+1],b[n+1][n+1],c[n+1][n+1];
inline int pos(int x,int y)
{
	if(x>=1&&x<=3){
		if(y>=1&&y<=3)return 1;
		else if(y>=4&&y<=6)return 2;
		else return 3;
	}
	else if(x>=4&&x<=6){
		if(y>=1&&y<=3)return 4;
		else if(y>=4&&y<=6)return 5;
		else return 6;
	}
	else{
		if(y>=1&&y<=3)return 7;
		else if(y>=4&&y<=6)return 8;
		else return 9;
	}
}
bool cmp(node a,node b)
{
	return a.cnt<b.cnt; 
} 
void dfs(int x,int y,int ans,int val)//x==ÐÐ£¬y==ÁÐ 
{
	if(mapp[x][y]!=0){
		if(val==9&&y==9){
			sum=max(sum,ans+mapp[x][y]*f[x][y]);
			return ;
		} 
		else if(y==9&&val!=9)
			dfs(m[val+1].id,1,ans+mapp[x][y]*f[x][y],val+1);
		else if(y!=9)
			dfs(x,y+1,ans+mapp[x][y]*f[x][y],val);
		else ;
	}
	else{
		for(int i=1;i<=9;i++){
			if(a[x][i]==0&&b[y][i]==0&&c[pos(x,y)][i]==0){
				a[x][i]=1,b[y][i]=1,c[pos(x,y)][i]=1;
				mapp[x][y]=i;
				if(val==9&&y==9){
					sum=max(sum,ans+mapp[x][y]*f[x][y]);
				}
				else if(val!=9&&y==9){
					dfs(m[val+1].id,1,ans+mapp[x][y]*f[x][y],val+1);
				}
				else if(y!=9){
					dfs(x,y+1,ans+mapp[x][y]*f[x][y],val);
				}
				else;
				a[x][i]=0,b[y][i]=0,c[pos(x,y)][i]=0;
				mapp[x][y]=0;
			}
		}
	}
}
int main(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		scanf("%d",&mapp[i][j]);
		a[i][mapp[i][j]]=1;
		b[j][mapp[i][j]]=1;
		c[pos(i,j)][mapp[i][j]]=1;
		if(mapp[i][j]==0)m[i].cnt++;
		}
		m[i].id=i;
	}
	sort(m+1,m+9+1,cmp);
	dfs(m[1].id,1,sum,1);
	printf("%d",sum==0?-1:sum);
	return 0;
}
