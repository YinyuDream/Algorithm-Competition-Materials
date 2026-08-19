#include<cstdio>
#include<cstring>
using namespace std;
long long n;
const int N=3,p=1e3;
struct node{
	long long map[N][N];
	node(){
		memset(map,0,sizeof map);
	}
	void build_e(){
		map[1][1]=map[2][1]=map[1][2]=1;
	}
}e,k;
node operator*(node a,node b)
{
	node c;
	for(int i=1;i<N;i++)
		for(int j=1;j<N;j++)
			for(int k=1;k<N;k++)
				c.map[i][j]=(c.map[i][j]%p+(a.map[i][k])%p*(b.map[k][j])%p)%p;
	return c;
};
node f(node a,long long b)
{
	if(b==0)return e;
	if(b==1)return a;
	node ans=f(a,b/2);
	if(b%2==0)ans=ans*ans;
	else ans=ans*ans*a;
	return ans;
}
int main(){
	scanf("%lld",&n);
	e.build_e();
	k.map[1][1]=k.map[1][2]=1;
	node m=f(e,n-1)*k;
	printf("%lld",m.map[1][1]%p);
	return 0;
}
