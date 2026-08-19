#include<cstdio>
#include<cstring>
using namespace std;
int p,q,n,m,a1,a2;
const int N=3;
struct node{
	int map[N][N];
	node(){
		memset(map,0,sizeof map);
	}
}e,k;
node operator*(node a,node b)
{
	node c;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			for(int k=1;k<N;k++)
				c.map[i][j]=(1ll*c.map[i][j]%m+(1ll*a.map[i][k]%m)*(1ll*b.map[k][j]%m))%m;
	return c;
};
node f(node a,int b)
{
	if(b==0){
		node c;
		c.map[1][1]=c.map[2][2]=1;
		return c;
	}
	node ans=f(a,b/2);
	if(b%2==0)ans=ans*ans;
	else ans=ans*ans*a;
	return ans;
}
int main(){
	scanf("%d%d%d%d%d%d",&p,&q,&a1,&a2,&n,&m);
	e.map[1][2]=q,e.map[2][1]=1,e.map[2][2]=p;
	k.map[1][1]=a1,k.map[1][2]=a2;
	node ans=k*f(e,n-1);
	printf("%d",ans.map[1][1]%m);
	return 0;
}
