#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=261;
const ll p=1e9+7;
int n,m,a,b;
struct matrix{
	ll num[N][N];
	matrix(){
		memset(num,0,sizeof num);
	}
}S,A,B,T,R,ans;
matrix operator*(const matrix &a,const matrix &b)
{
	matrix c;
	for(int i=1;i<=2*m;i++)
		for(int j=1;j<=2*m;j++)
			for(int k=1;k<=2*m;k++)
				(c.num[i][j]+=a.num[i][k]*b.num[k][j])%=p;
	return c;
}
int qpow(int a,int b)
{
	int ans=a;
	b--; 
	while(b){
		if(b&1)ans=1ll*ans*a%p;
		a=1ll*a*a%p;
		b>>=1;
	}
	return ans;
}
matrix qpow(matrix a,int b)
{
	matrix ans=a;
	b--;
	while(b){
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
void pre()
{
	R.num[1][m/2]=1;
	for(int i=1;i<=m;i++){
		if(i!=m)T.num[i][i+1]=1;
	    if(i!=1)T.num[i][i-1]=1;
		T.num[i][i]=1;
		if(i!=m)T.num[m+i][m+i+1]=1;
	    if(i!=1)T.num[m+i][m+i-1]=1;
	    T.num[m+i][m+i]=1;
	    if(i!=m)A.num[i][i+1]=1;
	    if(i!=1)A.num[i][i-1]=1;
		A.num[i][i]=1;
	}
	for(int i=a+1;i<=b-1;i++){
	    if(i!=1)B.num[i-1][i]=1;
	    if(i!=m)B.num[i+1][i]=1;
	    B.num[i][i]=1;
	}
	B=B*A;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)	
		T.num[m+i][j]=B.num[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			S.num[i][j+m]=A.num[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			S.num[i][j]=B.num[i][j];
}
int main(){
	freopen("bird.in","r",stdin);
	freopen("bird.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&a,&b);
	pre();
	ans=R*S*qpow(T,n-3);
	printf("%lld\n",ans.num[1][m/2]*qpow(n-2,p-2)%p);
	return 0;
}
