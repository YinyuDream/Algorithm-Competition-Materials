#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int T,n;
double f[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		f[n]=0;
		for(int i=n-1;i>=0;i--)
			f[i]=f[i+1]+1.0*n/(n-i);
		printf("%.2f\n",f[0]);
	}
	return 0;
}
