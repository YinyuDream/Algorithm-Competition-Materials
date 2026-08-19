#include<cstdio>
#define int long long
using namespace std;
int n,m,k,p;
int ansx[1000005],ansy[1000005];
main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&p);
	if(k/p<=m){
		int t=k/p;
		for(int i=1;i<=p;i++)
			ansx[i]=t,ansy[i]=m-t,k-=t;
		if(p<n){
			ansx[p+1]=k,ansy[p+1]=m-k,k=0;
			if(ansx[p]==ansx[p+1])return puts("NO"),0;
		}
		for(int i=p+2;i<=n;i++)
			ansx[i]=0,ansy[i]=m;
	}else{
		for(int i=1;i<=p;i++)
			ansx[i]=m,ansy[i]=0;
		k-=p*m;
		for(int i=p+1;i<=n;i++){
			if(k-(m-1)>=0)ansx[i]=m-1,ansy[i]=1,k-=m-1;
			else ansx[i]=k,ansy[i]=m-k,k=0;
		}
	}
	if(k)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%lld %lld\n",ansx[i],ansy[i]);
	return 0;
}
