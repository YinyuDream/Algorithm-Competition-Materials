#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int T,n;
int a[maxn];
long long ansmax,ansmin,b[maxn];
int main(){
	scanf("%d",&T);
	while(T--){
		ansmax=ansmin=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			ansmin+=n*a[i];
			b[i]=i*(n+1-i);
		}
		sort(b+1,b+n+1);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			ansmax+=(long long)a[i]*b[i];
		printf("%lld %lld\n",ansmin,ansmax);
	}
	return 0;
}