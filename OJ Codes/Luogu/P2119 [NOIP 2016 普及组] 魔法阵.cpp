#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n,m;
int t[maxn],num[maxn];
int A[maxn],B[maxn],C[maxn],D[maxn];

int main(){
	//freopen("magic.in","r",stdin);
	//freopen("magic.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&t[i]),
		num[t[i]]++;
	for(int k=1;k*9<n;k++)
	{
		int sum=0;
		int _a,_b,_c,_d;
		for(_d=k*9+2;_d<=n;_d++)
		{
			_a=_d-9*k-1;
			_b=_d-7*k-1;
			_c=_d-k;
			sum+=num[_a]*num[_b];
			C[_c]+=num[_d]*sum;
			D[_d]+=num[_c]*sum;
		}
		sum=0;
		for(_a=n-9*k-1;_a>=1;_a--)
		{
			_b=_a+2*k;
			_c=_a+k*8+1;
			_d=_a+k*9+1;
			sum+=num[_c]*num[_d];
			A[_a]+=num[_b]*sum;
			B[_b]+=num[_a]*sum;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d %d %d %d\n",A[t[i]],B[t[i]],C[t[i]],D[t[i]]);
}